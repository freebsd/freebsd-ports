diff -NBubrw lib/netdev-bsd.c.orig lib/netdev-bsd.c
--- lib/netdev-bsd.c.orig	1970-01-01 01:00:00.000000000 +0100
+++ lib/netdev-bsd.c	2011-11-28 15:13:26.920783291 +0100
@@ -0,0 +1,1577 @@
+/*
+ * Copyright (c) 2011 Gaetano Catalli. 
+ * 
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions are met:
+ * 
+ *    1. Redistributions of source code must retain the above copyright notice,
+ *       this list of conditions and the following disclaimer.
+ * 
+ *    2. Redistributions in binary form must reproduce the above copyright
+ *       notice, this list of conditions and the following disclaimer in the
+ *       documentation and/or other materials provided with the distribution.
+ * 
+ * THIS SOFTWARE IS PROVIDED ``AS IS'' WITHOUT ANY WARRANTIES OF ANY KIND.
+ *
+ */
+
+#include <stdlib.h>
+#include <config.h>
+#include <assert.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <sys/types.h>
+#include <sys/time.h>
+#include <sys/ioctl.h>
+#include <sys/socket.h>
+#include <sys/sockio.h>
+#include <ifaddrs.h>
+#include <pcap/pcap.h>
+#include <net/if.h>
+#include <net/if_dl.h>
+#include <net/if_media.h>
+#include <net/if_tap.h>
+#include <netinet/in.h>
+#include <net/if_mib.h>
+#include <poll.h>
+#include <string.h>
+#include <unistd.h>
+#include <sys/sysctl.h>
+
+#include "rtbsd.h"
+#include "coverage.h"
+#include "dynamic-string.h"
+#include "fatal-signal.h"
+#include "netdev-provider.h"
+#include "ofpbuf.h"
+#include "openflow/openflow.h"
+#include "packets.h"
+#include "poll-loop.h"
+#include "socket-util.h"
+#include "shash.h"
+#include "svec.h"
+#include "vlog.h"
+
+VLOG_DEFINE_THIS_MODULE(netdev_bsd)
+
+
+/*
+ * This file implements objects to access interfaces.
+ * Externally, interfaces are represented by two structures:
+ *   + struct netdev_dev, representing a network device,
+ *     containing e.g. name and a refcount;
+ *     We can have private variables by embedding the
+ *     struct netdev_dev into our own structure
+ *     (e.g. netdev_dev_bsd)
+ *
+ *   + struct netdev, representing an instance of an open netdev_dev.
+ *     The structure contains a pointer to the 'struct netdev'
+ *     representing the device. Again, private information
+ *     such as file descriptor etc. are stored in our
+ *     own struct netdev_bsd which includes a struct netdev.
+ *
+ * Both 'struct netdev' and 'struct netdev_dev' are referenced
+ * in containers which hold pointers to the data structures.
+ * We can reach our own struct netdev_XXX_bsd by putting a
+ * struct netdev_XXX within our own struct, and using CONTAINER_OF
+ * to access the parent structure.
+ */
+struct netdev_bsd {
+    struct netdev netdev;
+
+    int netdev_fd;   /* Selectable file descriptor for the network device.
+                        This descriptor will be used for polling operations */
+    
+    pcap_t *pcap_handle;  /* Packet capture descriptor for a system network
+                             device */
+};
+
+struct netdev_dev_bsd {
+    struct netdev_dev netdev_dev;
+    unsigned int cache_valid;
+
+    int ifindex;
+    uint8_t etheraddr[ETH_ADDR_LEN];
+    struct in_addr in4;
+    struct in6_addr in6;
+    int mtu;
+    int carrier;
+    
+    bool tap_opened;
+    int tap_fd;         /* TAP character device, if any */
+};
+
+
+enum {
+    VALID_IFINDEX = 1 << 0,
+    VALID_ETHERADDR = 1 << 1,
+    VALID_IN4 = 1 << 2,
+    VALID_IN6 = 1 << 3,
+    VALID_MTU = 1 << 4,
+    VALID_CARRIER = 1 << 5
+};
+
+/* An AF_INET socket (used for ioctl operations). */
+static int af_inet_sock = -1;
+
+#define PCAP_SNAPLEN 1024
+
+/*
+ * A BSD network device notifier.
+ *
+ * Represents a handler to be invoked on a device when some event occurs.
+ * Contains handler, parameters (in netdev_notifier) and link fields for the
+ * list (in struct list).
+ */
+struct netdev_bsd_notifier {
+    struct netdev_notifier notifier;    /* Handler and arguments */
+    struct list node;           /* Link fields for the list */
+};
+
+/*
+ * All 'struct netdev_bsd_notifier' objects are linked as children of a generic
+ * 'struct shash_node', there is one shash_node per interface, and the
+ * interface name is the search key.  In turn, all the 'struct shash_node' are
+ * stored in a container, all_bsd_notifiers.
+ *
+ * A 'netdev_bsd_notifier' is created and added to the all_bsd_notifiers
+ * using 'netdev_bsd_poll_add()' XXX again, same code as netdev-linux
+ */
+static struct shash all_bsd_notifiers =
+    SHASH_INITIALIZER(&all_bsd_notifiers);
+
+/* 
+ * Openvswitch can register multiple handlers on route-related events.
+ * The descriptor for each handler is a struct rtbsd_notifier
+ * that contains the function and a parameter.
+ *
+ * In this module we call rtbsd_notifier_register() to invoke
+ * the function netdev_bsd_poll_cb() on the all_bsd_notifiers above.
+ */
+static struct rtbsd_notifier netdev_bsd_poll_notifier;
+
+/*
+ * Notifier used to invalidate device informations in case of status change.
+ *
+ * It will be registered with a 'rtbsd_notifier_register()' when the first
+ * device will be created with the call of either 'netdev_bsd_tap_create()' or
+ * 'netdev_bsd_system_create()'.
+ *
+ * The callback associated with this notifier ('netdev_bsd_cache_cb()') will
+ * invalidate cached information about the device.
+ */
+static struct rtbsd_notifier netdev_bsd_cache_notifier;
+static int cache_notifier_refcount;
+
+static struct vlog_rate_limit rl = VLOG_RATE_LIMIT_INIT(5, 20);
+
+static int netdev_bsd_do_ioctl(const struct netdev *, struct ifreq *,
+                                 unsigned long cmd, const char *cmd_name);
+static void destroy_tap(int fd, const char *name);
+static int get_flags(const struct netdev *, int *flagsp);
+static int set_flags(struct netdev *, int flags);
+static int do_set_addr(struct netdev *netdev,
+                       int ioctl_nr, const char *ioctl_name,
+                       struct in_addr addr);
+static int get_etheraddr(const char *netdev_name, uint8_t ea[ETH_ADDR_LEN]);
+static int set_etheraddr(const char *netdev_name, int hwaddr_family,
+                         int hwaddr_len, const uint8_t[ETH_ADDR_LEN]);
+static int get_ifindex(const struct netdev *, int *ifindexp);
+
+static int netdev_bsd_init(void);
+
+static bool
+is_netdev_bsd_class(const struct netdev_class *netdev_class)
+{
+    return netdev_class->init == netdev_bsd_init;
+}
+
+static struct netdev_bsd *
+netdev_bsd_cast(const struct netdev *netdev)
+{
+    assert(is_netdev_bsd_class(netdev_dev_get_class(netdev_get_dev(netdev))));
+    return CONTAINER_OF(netdev, struct netdev_bsd, netdev);
+}
+
+static struct netdev_dev_bsd *
+netdev_dev_bsd_cast(const struct netdev_dev *netdev_dev)
+{
+    assert(is_netdev_bsd_class(netdev_dev_get_class(netdev_dev)));
+    return CONTAINER_OF(netdev_dev, struct netdev_dev_bsd, netdev_dev);
+}
+
+/* Initialize the AF_INET socket used for ioctl operations */
+static int
+netdev_bsd_init(void)
+{
+    static int status = -1;
+    
+    if (status >= 0) {  /* already initialized */
+        return status;
+    }
+
+    af_inet_sock = socket(AF_INET, SOCK_DGRAM, 0);
+    status = af_inet_sock >= 0 ? 0 : errno;
+
+    if (status) {
+        VLOG_ERR("failed to create inet socket: %s", strerror(status));
+    }
+        
+    return status;
+}
+
+/* 
+ * Perform periodic work needed by netdev. In BSD netdevs it checks for any
+ * interface status changes, and eventually calls all the user callbacks.
+ */
+static void
+netdev_bsd_run(void)
+{
+    rtbsd_notifier_run();
+}
+
+/* 
+ * Arranges for poll_block() to wake up if the "run" member function needs to
+ * be called. 
+ */
+static void
+netdev_bsd_wait(void)
+{
+    rtbsd_notifier_wait();
+}
+
+/* Invalidate cache in case of interface status change. */
+static void
+netdev_bsd_cache_cb(const struct rtbsd_change *change,
+                      void *aux OVS_UNUSED)
+{
+    struct netdev_dev_bsd *dev;
+    
+    if (change) {
+        struct netdev_dev *base_dev = netdev_dev_from_name(change->if_name);
+
+        if (base_dev) {
+            const struct netdev_class *netdev_class =
+                                                netdev_dev_get_class(base_dev);
+
+            if (is_netdev_bsd_class(netdev_class)) {
+                dev = netdev_dev_bsd_cast(base_dev);
+                dev->cache_valid = 0;
+            }
+        }
+    } else {
+        /*
+         * XXX the API is lacking, we should be able to iterate on the list of
+         * netdevs without having to store the info in a temp shash.
+         */
+        struct shash device_shash;
+        struct shash_node *node;
+
+        shash_init(&device_shash);
+        netdev_dev_get_devices(&netdev_bsd_class, &device_shash);
+        SHASH_FOR_EACH (node, &device_shash) {
+            dev = node->data;
+            dev->cache_valid = 0;
+        }
+        shash_destroy(&device_shash);
+    }
+}
+
+/* Allocate a netdev_dev_bsd structure */
+static int
+netdev_bsd_create_system(const char *name, const char *type OVS_UNUSED,
+                  const struct shash *args OVS_UNUSED, 
+                  struct netdev_dev **netdev_devp)
+{
+    struct netdev_dev_bsd *netdev_dev;
+    int ret = 0;
+
+    if (!cache_notifier_refcount) {
+        ret = rtbsd_notifier_register(&netdev_bsd_cache_notifier,
+                                                netdev_bsd_cache_cb, NULL);
+        if (ret) {
+            return ret;
+        }
+    }
+    cache_notifier_refcount++;
+
+    netdev_dev = xzalloc(sizeof *netdev_dev);
+    netdev_dev_init(&netdev_dev->netdev_dev, name, &netdev_bsd_class);
+    *netdev_devp = &netdev_dev->netdev_dev;
+
+    return ret;
+}
+
+/* 
+ * Allocate a netdev_dev_bsd structure with 'tap' class.
+ */
+static int
+netdev_bsd_create_tap(const char *name, const char *type OVS_UNUSED,
+                  const struct shash *args OVS_UNUSED, 
+                  struct netdev_dev **netdev_devp)
+{
+    struct netdev_dev_bsd *netdev_dev;
+    int error = 0;
+    struct ifreq ifr;
+
+    if (!cache_notifier_refcount) {
+        error = rtbsd_notifier_register(&netdev_bsd_cache_notifier,
+                                                netdev_bsd_cache_cb, NULL);
+        if (error) {
+            return error;
+        }
+    }
+    cache_notifier_refcount++;
+
+    /* allocate the device structure and set the internal flag */
+    netdev_dev = xzalloc(sizeof *netdev_dev);
+    
+    memset(&ifr, 0, sizeof(ifr));
+
+    /* Create a tap device by opening /dev/tap.  The TAPGIFNAME ioctl is used
+     * to retrieve the name of the tap device. */
+    netdev_dev->tap_fd = open("/dev/tap", O_RDWR);
+    if (netdev_dev->tap_fd < 0) {
+        error = errno;
+        VLOG_WARN("opening \"/dev/tap\" failed: %s", strerror(error));
+        goto error;
+    }
+    
+    /* Retrieve tap name (e.g. tap0) */
+    if (ioctl(netdev_dev->tap_fd, TAPGIFNAME, &ifr) == -1) {
+        /* XXX Need to destroy the device? */
+        error = errno;
+        goto error;
+    }
+    
+    /* Change the name of the tap device */
+    ifr.ifr_data = (void *)name;
+    if (ioctl(af_inet_sock, SIOCSIFNAME, &ifr) == -1) {
+        error = errno;
+        destroy_tap(netdev_dev->tap_fd, ifr.ifr_name);
+        goto error;
+    }
+
+    /* set non-blocking. */
+    error = set_nonblocking(netdev_dev->tap_fd);
+    if (error) {
+        destroy_tap(netdev_dev->tap_fd, name);
+        goto error;
+    }
+ 
+    /* Turn device UP */
+    ifr.ifr_flags = (uint16_t)IFF_UP;
+    ifr.ifr_flagshigh = 0;
+    strncpy(ifr.ifr_name, name, sizeof ifr.ifr_name);
+    if (ioctl(af_inet_sock, SIOCSIFFLAGS, &ifr) == -1) {
+        error = errno;
+        destroy_tap(netdev_dev->tap_fd, name);
+        goto error;
+    }
+
+    /* initialize the device structure and
+     * link the structure to its netdev */
+    netdev_dev_init(&netdev_dev->netdev_dev, name, &netdev_tap_class);
+    *netdev_devp = &netdev_dev->netdev_dev;
+
+    return 0;
+
+error:
+    free(netdev_dev);
+    return error;
+}
+
+static void
+netdev_bsd_destroy(struct netdev_dev *netdev_dev_)
+{
+    struct netdev_dev_bsd *netdev_dev = netdev_dev_bsd_cast(netdev_dev_);
+
+    cache_notifier_refcount--;
+    if (cache_notifier_refcount == 0) {
+        rtbsd_notifier_unregister(&netdev_bsd_cache_notifier);
+    }
+
+    if (netdev_dev->tap_fd >= 0 && 
+            !strcmp(netdev_dev_get_type(netdev_dev_), "tap")) {
+        destroy_tap(netdev_dev->tap_fd, netdev_dev_get_name(netdev_dev_));
+    }
+    free(netdev_dev);
+}
+
+
+static int
+netdev_bsd_open_system(struct netdev_dev *netdev_dev_, int ethertype,
+                       struct netdev **netdevp)
+{
+    struct netdev_dev_bsd *netdev_dev = netdev_dev_bsd_cast(netdev_dev_);
+    struct netdev_bsd *netdev;
+    int error;
+    enum netdev_flags flags;
+    
+    /* Allocate network device. */
+    netdev = xcalloc(1, sizeof *netdev);
+    netdev->netdev_fd = -1;
+    netdev_init(&netdev->netdev, netdev_dev_);
+
+    /* Verify that the netdev really exists by attempting to read its flags */
+    error = netdev_get_flags(&netdev->netdev, &flags);
+    if (error == ENXIO) {
+        goto error;
+    }
+
+    /* The first user that opens a tap port(from dpif_create_and_open()) will
+     * receive the file descriptor associated with the tap device. Instead, the
+     * following users will open the tap device as a normal 'system' device. */
+    if (!strcmp(netdev_dev_get_type(netdev_dev_), "tap") &&
+            !netdev_dev->tap_opened) {
+        netdev_dev->tap_opened = true;
+        netdev->netdev_fd = netdev_dev->tap_fd;
+    } else if (ethertype != NETDEV_ETH_TYPE_NONE) {
+        char errbuf[PCAP_ERRBUF_SIZE];
+        int one = 1;
+
+        /* open the pcap device. The device is opened in non-promiscuous mode
+         * because the interface flags are manually set by the caller. */
+        netdev->pcap_handle = pcap_open_live(netdev_dev_->name, PCAP_SNAPLEN,
+                                             0, 1000, errbuf);
+        if (netdev->pcap_handle == NULL) {
+            error = errno;
+            goto error;
+        }
+
+        /* initialize netdev->netdev_fd */
+        netdev->netdev_fd = pcap_get_selectable_fd(netdev->pcap_handle);
+        if (netdev->netdev_fd == -1) {
+            error = errno;
+            goto error;
+        }
+
+        /* Set non-blocking mode. Also the BIOCIMMEDIATE ioctl must be called
+         * on the file descriptor returned by pcap_get_selectable_fd to achieve
+         * a real non-blocking behaviour.*/
+        error = pcap_setnonblock(netdev->pcap_handle, 1, errbuf);
+        if (error == -1) {
+            error = errno;
+            goto error;
+        }
+        
+        /* This call assure that reads return immediately upon packet reception.
+         * Otherwise, a read will block until either the kernel buffer becomes
+         * full or a timeout occurs. */
+        if(ioctl(netdev->netdev_fd, BIOCIMMEDIATE, &one) < 0 ) {
+            VLOG_ERR("ioctl(BIOCIMMEDIATE) on %s device failed: %s",
+                     netdev_dev_get_name(netdev_dev_), strerror(errno));
+            error = errno;
+            goto error;
+        }
+
+        /* Capture only incoming packets */
+        error = pcap_setdirection(netdev->pcap_handle, PCAP_D_IN);
+        if (error == -1) {
+            error = errno;
+            goto error;
+        }
+    }
+    *netdevp = &netdev->netdev;
+
+    return 0;
+
+error:
+    netdev_uninit(&netdev->netdev, true);
+    return error;
+}
+
+
+/* Close a 'netdev'. */
+static void
+netdev_bsd_close(struct netdev *netdev_)
+{
+    struct netdev_bsd *netdev = netdev_bsd_cast(netdev_);
+
+    if (netdev->netdev_fd >= 0 && strcmp(netdev_get_type(netdev_), "tap")) {
+        pcap_close(netdev->pcap_handle);
+    }
+
+    free(netdev);
+}
+
+
+/* Initializes 'svec' with a list of the names of all known network devices. */
+static int
+netdev_bsd_enumerate(struct svec *svec)
+{
+    struct if_nameindex *names;
+
+    names = if_nameindex();
+    if (names) {
+        size_t i;
+
+        for (i = 0; names[i].if_name != NULL; i++) {
+            svec_add(svec, names[i].if_name);
+        }
+        if_freenameindex(names);
+        return 0;
+    } else {
+        VLOG_WARN("could not obtain list of network device names: %s",
+                  strerror(errno));
+        return errno;
+    }
+}
+
+/* The recv callback of the netdev class returns the number of bytes of the
+ * received packet.
+ *
+ * This can be done by the pcap_next() function. Unfortunately pcap_next() does
+ * not make difference between a missing packet on the capture interface and
+ * an error during the file capture.  We can use the pcap_dispatch() function 
+ * instead, which is able to distinguish between errors and null packet.
+ *
+ * To make pcap_dispatch() returns the number of bytes read from the interface
+ * we need to define the following callback and argument. 
+ */
+struct pcap_arg {
+    void *data;
+    int size;
+    int retval;
+};
+
+/*
+ * This callback will be executed on every captured packet.
+ * 
+ * If the packet captured by pcap_dispatch() does not fit the pcap buffer,
+ * pcap returns a truncated packet and we follow this behavior.
+ *
+ * The argument args->retval is the packet size in bytes.
+ */
+static void 
+proc_pkt(u_char *args_, const struct pcap_pkthdr *hdr, const u_char *packet)
+{
+    struct pcap_arg *args = (struct pcap_arg *)args_;
+
+    if (args->size < hdr->len) {
+        printf("%s Warning: Packet truncated'n", __func__);
+        args->retval = args->size;
+    } else {
+        args->retval = hdr->len;
+    }
+
+    /* copy the packet to our buffer */
+    memcpy(args->data, packet, args->retval);
+}
+
+/*
+ * This function attempts to receive a packet from the specified network
+ * device. It is assumed that the network device is a system device or a tap
+ * device opened as a system one. In this case the read operation is performed
+ * on the 'netdev' pcap descriptor.
+ */
+static int
+netdev_bsd_recv_system(struct netdev_bsd *netdev, void *data, size_t size)
+{
+    struct pcap_arg arg;
+    int ret;
+
+    if (netdev->netdev_fd < 0) {
+        /* Device was opened with NETDEV_ETH_TYPE_NONE. */
+        return -EAGAIN;
+    }
+    
+    /* prepare the pcap argument to store the packet */
+    arg.size = size;
+    arg.data = data;
+
+    for (;;) {
+        ret = pcap_dispatch(netdev->pcap_handle, 1, proc_pkt, (u_char *)&arg);
+
+        if (ret > 0) {
+            return arg.retval;	/* arg.retval < 0 is handled in the caller */
+        }
+        if (ret == -1) {
+            if (errno == EINTR) {
+                 continue;
+            }
+        }
+
+        return -EAGAIN;
+    }
+}
+
+/*
+ * This function attempts to receive a packet from the specified network
+ * device. It is assumed that the network device is a tap device and the
+ * 'netdev_fd' member of the 'netdev' structure is initialized with the tap
+ * file descriptor.
+ */
+static int
+netdev_bsd_recv_tap(struct netdev_bsd *netdev, void *data, size_t size)
+{
+    if (netdev->netdev_fd < 0) {
+        /* Device was opened with NETDEV_ETH_TYPE_NONE. */
+        return -EAGAIN;
+    }
+    
+    for (;;) {
+        ssize_t retval = read(netdev->netdev_fd, data, size);
+        if (retval >= 0) {
+            return retval;
+        } else if (errno != EINTR) {
+            if (errno != EAGAIN) {
+                VLOG_WARN_RL(&rl, "error receiving Ethernet packet on %s: %s",
+                             strerror(errno), netdev->netdev.netdev_dev->name);
+            }
+            return -errno;
+        }
+    }
+}
+
+
+/*
+ * According with the nature of the device a different function must be called.
+ * If the device is the bridge local port the 'netdev_bsd_recv_tap' function
+ * must be called, otherwise the 'netdev_bsd_recv_system' function is called.
+ *
+ * type!="tap"                                        --->  system device.
+ * type=="tap" && netdev_fd == tap_fd                 --->  internal tap device
+ * type=="tap" && netdev_fd != tap_fd                 --->  internal tap device
+ *                                                          opened as a system
+ *                                                          device. 
+ */
+static int
+netdev_bsd_recv(struct netdev *netdev_, void* data, size_t size)
+{
+    struct netdev_bsd *netdev = netdev_bsd_cast(netdev_);
+    struct netdev_dev_bsd * netdev_dev =
+        netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+
+    if (!strcmp(netdev_get_type(netdev_), "tap") && 
+            netdev->netdev_fd == netdev_dev->tap_fd) {
+        return netdev_bsd_recv_tap(netdev, data, size);
+    } else {
+        return netdev_bsd_recv_system(netdev, data, size);
+    }
+}
+
+
+/* 
+ * Registers with the poll loop to wake up from the next call to poll_block()
+ * when a packet is ready to be received with netdev_recv() on 'netdev'.
+ */
+static void
+netdev_bsd_recv_wait(struct netdev *netdev_)
+{
+    struct netdev_bsd *netdev = netdev_bsd_cast(netdev_);
+
+    if (netdev->netdev_fd >= 0) {
+        poll_fd_wait(netdev->netdev_fd, POLLIN);
+    }
+}
+
+/* Discards all packets waiting to be received from 'netdev'. */
+static int
+netdev_bsd_drain(struct netdev *netdev_)
+{
+    struct ifreq ifr;
+    struct netdev_bsd *netdev = netdev_bsd_cast(netdev_);
+
+    strcpy(ifr.ifr_name, netdev_get_name(netdev_));
+    if (ioctl(netdev->netdev_fd, BIOCFLUSH, &ifr) == -1) {
+        VLOG_DBG_RL(&rl, "%s: ioctl(BIOCFLUSH) failed: %s",
+                    netdev_get_name(netdev_), strerror(errno));
+        return errno;
+    }
+    return 0;
+}
+
+/* 
+ * Send a packet on the specified network device. The device could be either a
+ * system or a tap device.
+ */
+static int
+netdev_bsd_send(struct netdev *netdev_, const void *data, size_t size)
+{
+    struct netdev_bsd *netdev = netdev_bsd_cast(netdev_);
+    struct netdev_dev_bsd * netdev_dev =
+        netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+
+    /* XXX should support sending even if 'ethertype' was NETDEV_ETH_TYPE_NONE.
+     */
+    if (netdev->netdev_fd < 0) {
+        return EPIPE;
+    }
+
+    for (;;) {
+        ssize_t retval;
+        if (!strcmp(netdev_get_type(netdev_), "tap") && 
+                netdev_dev->tap_fd == netdev->netdev_fd) {
+            retval = write(netdev->netdev_fd, data, size);
+        } else {
+            retval = pcap_inject(netdev->pcap_handle, data, size);
+        }
+        if (retval < 0) {
+            if (errno == EINTR) {
+                continue;
+            } else if (errno != EAGAIN) {
+                VLOG_WARN_RL(&rl, "error sending Ethernet packet on %s: %s",
+                             netdev_get_name(netdev_), strerror(errno));
+            }
+            return errno;
+        } else if (retval != size) {
+            VLOG_WARN_RL(&rl, "sent partial Ethernet packet (%zd bytes of "
+                         "%zu) on %s", retval, size,
+                         netdev_get_name(netdev_));
+           return EMSGSIZE;
+        } else {
+            return 0;
+        }
+    }
+}
+
+/*
+ * Registers with the poll loop to wake up from the next call to poll_block()
+ * when the packet transmission queue has sufficient room to transmit a packet
+ * with netdev_send().
+ */
+static void
+netdev_bsd_send_wait(struct netdev *netdev_)
+{
+    struct netdev_bsd *netdev = netdev_bsd_cast(netdev_);
+
+    if (netdev->netdev_fd < 0) { /* Nothing to do. */
+        return;
+    }
+
+    if (strcmp(netdev_get_type(netdev_), "tap")) {
+        poll_fd_wait(netdev->netdev_fd, POLLOUT);
+    } else {
+        /* TAP device always accepts packets. */
+        poll_immediate_wake();
+    }
+}
+
+/*
+ * Attempts to set 'netdev''s MAC address to 'mac'.  Returns 0 if successful,
+ * otherwise a positive errno value.
+ */
+static int
+netdev_bsd_set_etheraddr(struct netdev *netdev_,
+                           const uint8_t mac[ETH_ADDR_LEN])
+{
+    struct netdev_dev_bsd *netdev_dev =
+                                netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+    int error;
+    
+    if (!(netdev_dev->cache_valid & VALID_ETHERADDR)
+        || !eth_addr_equals(netdev_dev->etheraddr, mac)) {
+        error = set_etheraddr(netdev_get_name(netdev_), AF_LINK, ETH_ADDR_LEN,
+                              mac);
+        if (!error) {
+            netdev_dev->cache_valid |= VALID_ETHERADDR;
+            memcpy(netdev_dev->etheraddr, mac, ETH_ADDR_LEN);
+        }
+    } else {
+        error = 0;
+    }
+    return error;
+}
+
+/*
+ * Returns a pointer to 'netdev''s MAC address.  The caller must not modify or
+ * free the returned buffer.
+ */
+static int
+netdev_bsd_get_etheraddr(const struct netdev *netdev_,
+                           uint8_t mac[ETH_ADDR_LEN])
+{
+    struct netdev_dev_bsd *netdev_dev =
+        netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+    
+    if (!(netdev_dev->cache_valid & VALID_ETHERADDR)) {
+        int error = get_etheraddr(netdev_get_name(netdev_), 
+                                  netdev_dev->etheraddr);
+        if (error) {
+            return error;
+        }
+        netdev_dev->cache_valid |= VALID_ETHERADDR;
+    }
+    memcpy(mac, netdev_dev->etheraddr, ETH_ADDR_LEN);
+    
+    return 0;
+}
+
+/*
+ * Returns the maximum size of transmitted (and received) packets on 'netdev',
+ * in bytes, not including the hardware header; thus, this is typically 1500
+ * bytes for Ethernet devices.
+ */
+static int
+netdev_bsd_get_mtu(const struct netdev *netdev_, int *mtup)
+{
+    struct netdev_dev_bsd *netdev_dev = 
+        netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+    
+    if (!(netdev_dev->cache_valid & VALID_MTU)) {
+        struct ifreq ifr;
+        int error;
+
+        error = netdev_bsd_do_ioctl(netdev_, &ifr, SIOCGIFMTU, "SIOCGIFMTU");
+        if (error) {
+            return error;
+        }
+        netdev_dev->mtu = ifr.ifr_mtu;
+        netdev_dev->cache_valid |= VALID_MTU;
+    }
+
+    *mtup = netdev_dev->mtu;
+    return 0;
+}
+
+static int
+netdev_bsd_get_ifindex(const struct netdev *netdev)
+{
+    int ifindex, error;
+    
+    error = get_ifindex(netdev, &ifindex);
+    return error ? -error : ifindex;
+}
+
+static int
+netdev_bsd_get_carrier(const struct netdev *netdev_, bool *carrier)
+{
+    struct netdev_dev_bsd *netdev_dev =
+        netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+    
+    if (!(netdev_dev->cache_valid & VALID_CARRIER)) {
+        struct ifmediareq ifmr;
+
+        memset(&ifmr, 0, sizeof(ifmr));
+        strncpy(ifmr.ifm_name, netdev_get_name(netdev_), sizeof ifmr.ifm_name);
+
+        if (ioctl(af_inet_sock, SIOCGIFMEDIA, &ifmr) == -1) {
+            VLOG_DBG_RL(&rl, "%s: ioctl(SIOCGIFMEDIA) failed: %s",
+                        netdev_get_name(netdev_), strerror(errno));
+            return errno;
+        }
+
+        netdev_dev->carrier = (ifmr.ifm_status & IFM_ACTIVE) == IFM_ACTIVE;
+        netdev_dev->cache_valid |= VALID_CARRIER;
+
+        /* If the interface doesn't report whether the media is active,
+         * just assume it is active. */
+        if ((ifmr.ifm_status & IFM_AVALID) == 0) {
+            netdev_dev->carrier = true;
+        }
+    }
+    *carrier = netdev_dev->carrier;
+    
+    return 0;
+}
+
+/* Retrieves current device stats for 'netdev'. */
+static int
+netdev_bsd_get_stats(const struct netdev *netdev_, struct netdev_stats *stats)
+{
+    int if_count, i;
+    int mib[6];
+    size_t len;
+    struct ifmibdata ifmd;
+
+    COVERAGE_INC(netdev_get_stats);
+
+    mib[0] = CTL_NET;
+    mib[1] = PF_LINK;
+    mib[2] = NETLINK_GENERIC;
+    mib[3] = IFMIB_SYSTEM;
+    mib[4] = IFMIB_IFCOUNT;
+
+    len = sizeof(if_count);
+
+    if (sysctl(mib, 5, &if_count, &len, (void *)0, 0) == -1) {
+        VLOG_DBG_RL(&rl, "%s: sysctl failed: %s",
+                    netdev_get_name(netdev_), strerror(errno));
+        return errno;
+    }
+    
+    mib[5] = IFDATA_GENERAL;
+    mib[3] = IFMIB_IFDATA;
+    len = sizeof(ifmd);
+    for (i = 1; i <= if_count; i++) {
+        mib[4] = i; //row
+        if (sysctl(mib, 6, &ifmd, &len, (void *)0, 0) == -1) {
+            VLOG_DBG_RL(&rl, "%s: sysctl failed: %s",
+                        netdev_get_name(netdev_), strerror(errno));
+            return errno;
+        } else if (!strcmp(ifmd.ifmd_name, netdev_get_name(netdev_))) {
+            stats->rx_packets = ifmd.ifmd_data.ifi_ipackets;        
+            stats->tx_packets = ifmd.ifmd_data.ifi_opackets;
+            stats->rx_bytes = ifmd.ifmd_data.ifi_ibytes;          
+            stats->tx_bytes = ifmd.ifmd_data.ifi_obytes;          
+            stats->rx_errors = ifmd.ifmd_data.ifi_ierrors;         
+            stats->tx_errors = ifmd.ifmd_data.ifi_oerrors;       
+            stats->rx_dropped = ifmd.ifmd_data.ifi_iqdrops;        
+            stats->tx_dropped = 0;        
+            stats->multicast = ifmd.ifmd_data.ifi_imcasts;         
+            stats->collisions = ifmd.ifmd_data.ifi_collisions;
+
+            stats->rx_length_errors = 0;
+            stats->rx_over_errors = 0;   
+            stats->rx_crc_errors = 0;  
+            stats->rx_frame_errors = 0;
+            stats->rx_fifo_errors = 0;    
+            stats->rx_missed_errors = 0;  
+
+            stats->tx_aborted_errors = 0;
+            stats->tx_carrier_errors = 0;
+            stats->tx_fifo_errors = 0;
+            stats->tx_heartbeat_errors = 0;
+            stats->tx_window_errors = 0;
+            break;
+        }
+    }
+
+    return 0;
+}
+
+static uint32_t
+netdev_bsd_parse_media(int media)
+{
+    uint32_t supported = 0;
+    bool half_duplex = media & IFM_HDX ? true : false;
+
+    switch (IFM_SUBTYPE(media)) {
+    case IFM_10_2:
+    case IFM_10_5:
+    case IFM_10_STP:
+    case IFM_10_T:
+        supported |= half_duplex ? OFPPF_10MB_HD : OFPPF_10MB_FD;
+        supported |= OFPPF_COPPER;
+        break;
+
+    case IFM_10_FL:
+        supported |= half_duplex ? OFPPF_10MB_HD : OFPPF_10MB_FD;
+        supported |= OFPPF_FIBER;
+        break;
+
+    case IFM_100_T2:
+    case IFM_100_T4:
+    case IFM_100_TX:
+    case IFM_100_VG:
+        supported |= half_duplex ? OFPPF_100MB_HD : OFPPF_100MB_FD;
+        supported |= OFPPF_COPPER;
+        break;
+
+    case IFM_100_FX:
+        supported |= half_duplex ? OFPPF_100MB_HD : OFPPF_100MB_FD;
+        supported |= OFPPF_FIBER;
+        break;
+
+    case IFM_1000_CX:
+    case IFM_1000_T:
+        supported |= half_duplex ? OFPPF_1GB_HD : OFPPF_1GB_FD;
+        supported |= OFPPF_COPPER;
+        break;
+
+    case IFM_1000_LX:
+    case IFM_1000_SX:
+        supported |= half_duplex ? OFPPF_1GB_HD : OFPPF_1GB_FD;
+        supported |= OFPPF_FIBER;
+        break;
+
+    case IFM_10G_CX4:
+        supported |= OFPPF_10GB_FD;
+        supported |= OFPPF_COPPER;
+        break;
+
+    case IFM_10G_LR:
+    case IFM_10G_SR:
+        supported |= OFPPF_10GB_FD;
+        supported |= OFPPF_FIBER;
+        break;
+
+    default:
+        return 0;
+    }
+
+    if (IFM_SUBTYPE(media) == IFM_AUTO) {
+        supported |= OFPPF_AUTONEG;
+    }
+    /*
+    if (media & IFM_ETH_FMASK) {
+        supported |= OFPPF_PAUSE;
+    }
+    */
+
+    return supported;
+}
+
+/* 
+ * Stores the features supported by 'netdev' into each of '*current',
+ * '*advertised', '*supported', and '*peer' that are non-null.  Each value is a
+ * bitmap of "enum ofp_port_features" bits, in host byte order.  Returns 0 if
+ * successful, otherwise a positive errno value.  On failure, all of the
+ * passed-in values are set to 0.
+ */
+static int
+netdev_bsd_get_features(struct netdev *netdev,
+                          uint32_t *current, uint32_t *advertised,
+                          uint32_t *supported, uint32_t *peer)
+{
+    struct ifmediareq ifmr;
+    int *media_list;
+    int i;
+    int error;
+
+
+    /* XXX Look into SIOCGIFCAP instead of SIOCGIFMEDIA */
+
+    memset(&ifmr, 0, sizeof(ifmr));
+    strncpy(ifmr.ifm_name, netdev_get_name(netdev), sizeof ifmr.ifm_name);
+
+    /* We make two SIOCGIFMEDIA ioctl calls.  The first to determine the
+     * number of supported modes, and a second with a buffer to retrieve
+     * them. */
+    if (ioctl(af_inet_sock, SIOCGIFMEDIA, &ifmr) == -1) {
+        VLOG_DBG_RL(&rl, "%s: ioctl(SIOCGIFMEDIA) failed: %s",
+                    netdev_get_name(netdev), strerror(errno));
+        return errno;
+    }
+
+    media_list = xcalloc(ifmr.ifm_count, sizeof(int));
+    ifmr.ifm_ulist = media_list;
+
+    if (!IFM_TYPE(ifmr.ifm_current) & IFM_ETHER) {
+        VLOG_DBG_RL(&rl, "%s: doesn't appear to be ethernet",
+                    netdev_get_name(netdev));
+        error = EINVAL;
+        goto cleanup;
+    }
+
+    if (ioctl(af_inet_sock, SIOCGIFMEDIA, &ifmr) == -1) {
+        VLOG_DBG_RL(&rl, "%s: ioctl(SIOCGIFMEDIA) failed: %s",
+                    netdev_get_name(netdev), strerror(errno));
+        error = errno;
+        goto cleanup;
+    }
+
+    /* Current settings. */
+    *current = netdev_bsd_parse_media(ifmr.ifm_active);
+
+    /* Advertised features. */
+    *advertised = netdev_bsd_parse_media(ifmr.ifm_current);
+
+    /* Supported features. */
+    *supported = 0;
+    for (i = 0; i < ifmr.ifm_count; i++) {
+        *supported |= netdev_bsd_parse_media(ifmr.ifm_ulist[i]);
+    }
+
+    /* Peer advertisements. */
+    *peer = 0;                  /* XXX */
+
+    error = 0;
+cleanup:
+    free(media_list);
+    return error;
+}
+
+/*
+ * If 'netdev' has an assigned IPv4 address, sets '*in4' to that address (if
+ * 'in4' is non-null) and returns true.  Otherwise, returns false.
+ */
+static int
+netdev_bsd_get_in4(const struct netdev *netdev_, struct in_addr *in4, 
+                   struct in_addr *netmask)
+{
+    struct netdev_dev_bsd *netdev_dev =
+        netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+
+    if (!(netdev_dev->cache_valid & VALID_IN4)) {
+        const struct sockaddr_in *sin;
+        struct ifreq ifr;
+        int error;
+
+        ifr.ifr_addr.sa_family = AF_INET;
+        error = netdev_bsd_do_ioctl(netdev_, &ifr,
+                                      SIOCGIFADDR, "SIOCGIFADDR");
+        if (error) {
+            return error;
+        }
+
+        sin = (struct sockaddr_in *) &ifr.ifr_addr;
+        netdev_dev->in4 = sin->sin_addr;
+        netdev_dev->cache_valid |= VALID_IN4;
+        error = netdev_bsd_do_ioctl(netdev_, &ifr,
+                                      SIOCGIFNETMASK, "SIOCGIFNETMASK");
+        if (error) {
+            return error;
+        }
+        *netmask = ((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr;
+    }
+    *in4 = netdev_dev->in4;
+
+    return in4->s_addr == INADDR_ANY ? EADDRNOTAVAIL : 0;
+}
+
+/*
+ * Assigns 'addr' as 'netdev''s IPv4 address and 'mask' as its netmask.  If
+ * 'addr' is INADDR_ANY, 'netdev''s IPv4 address is cleared.  Returns a
+ * positive errno value.
+ */
+static int
+netdev_bsd_set_in4(struct netdev *netdev_, struct in_addr addr,
+                     struct in_addr mask)
+{
+    struct netdev_dev_bsd *netdev_dev =
+        netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+    int error;
+    
+    error = do_set_addr(netdev_, SIOCSIFADDR, "SIOCSIFADDR", addr);
+    if (!error) {
+        netdev_dev->cache_valid |= VALID_IN4;
+        netdev_dev->in4 = addr;
+        if (addr.s_addr != INADDR_ANY) {
+            error = do_set_addr(netdev_, SIOCSIFNETMASK,
+                                "SIOCSIFNETMASK", mask);
+        }
+    }
+    return error;
+}
+
+static int
+netdev_bsd_get_in6(const struct netdev *netdev_, struct in6_addr *in6)
+{
+    struct netdev_dev_bsd *netdev_dev =
+                                netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+    if (!(netdev_dev->cache_valid & VALID_IN6)) {
+        struct ifaddrs *ifa, *head;
+        struct sockaddr_in6 *sin6;
+        const char *netdev_name = netdev_get_name(netdev_);
+
+        if (getifaddrs(&head) != 0) {
+            VLOG_ERR("getifaddrs on %s device failed: %s", netdev_name, 
+                    strerror(errno));
+            return errno;
+        }
+
+        for (ifa = head; ifa; ifa = ifa->ifa_next) {
+            if (ifa->ifa_addr->sa_family == AF_INET6 && 
+                    !strcmp(ifa->ifa_name, netdev_name)) {
+                sin6 = (struct sockaddr_in6 *)ifa->ifa_addr;
+                if (sin6) {
+                    memcpy(&netdev_dev->in6, &sin6->sin6_addr, sin6->sin6_len);
+                    netdev_dev->cache_valid |= VALID_IN6;
+                    *in6 = netdev_dev->in6;
+                    freeifaddrs(head);
+                    return 0;
+                } 
+            }
+        }
+        return EADDRNOTAVAIL;
+    }
+    *in6 = netdev_dev->in6;
+    return 0;
+}
+
+static void
+make_in4_sockaddr(struct sockaddr *sa, struct in_addr addr)
+{
+    struct sockaddr_in sin;
+    memset(&sin, 0, sizeof sin);
+    sin.sin_family = AF_INET;
+    sin.sin_addr = addr;
+    sin.sin_port = 0;
+
+    memset(sa, 0, sizeof *sa);
+    memcpy(sa, &sin, sizeof sin);
+}
+
+static int
+do_set_addr(struct netdev *netdev,
+            int ioctl_nr, const char *ioctl_name, struct in_addr addr)
+{
+    struct ifreq ifr;
+    make_in4_sockaddr(&ifr.ifr_addr, addr);
+    return netdev_bsd_do_ioctl(netdev, &ifr, ioctl_nr, ioctl_name);
+}
+
+static int
+nd_to_iff_flags(enum netdev_flags nd)
+{
+    int iff = 0;
+    if (nd & NETDEV_UP) {
+        iff |= IFF_UP;
+    }
+    if (nd & NETDEV_PROMISC) {
+        iff |= IFF_PROMISC;
+        iff |= IFF_PPROMISC;
+    }
+    return iff;
+}
+
+static int
+iff_to_nd_flags(int iff)
+{
+    enum netdev_flags nd = 0;
+    if (iff & IFF_UP) {
+        nd |= NETDEV_UP;
+    }
+    if (iff & IFF_PROMISC) { 
+        nd |= NETDEV_PROMISC;
+    }
+    return nd;
+}
+
+static int
+netdev_bsd_update_flags(struct netdev *netdev, enum netdev_flags off,
+                          enum netdev_flags on, enum netdev_flags *old_flagsp)
+{
+    int old_flags, new_flags;
+    int error;
+
+    error = get_flags(netdev, &old_flags);
+    if (!error) {
+        *old_flagsp = iff_to_nd_flags(old_flags);
+        new_flags = (old_flags & ~nd_to_iff_flags(off)) | nd_to_iff_flags(on);
+        if (new_flags != old_flags) {
+            error = set_flags(netdev, new_flags);
+        }
+    }
+    return error;
+}
+
+/* Call callbacks for all the list of notifiers */
+static void
+poll_notify(struct list *dev_notifiers)
+{
+    struct netdev_bsd_notifier *notifier;
+    LIST_FOR_EACH (notifier, struct netdev_bsd_notifier, node, dev_notifiers) {
+        struct netdev_notifier *n = &notifier->notifier;
+        n->cb(n);
+    }
+}
+
+/*
+ * The callback registered for 'netdev_bsd_poll_notifier'.
+ *
+ * If 'change' is set it retrieves the element in the 'all_bsd_notifiers'
+ * relative to the network device which has been subject to the change, and
+ * then call the callbacks for all the notifiers registered for that network
+ * device.
+ */
+static void
+netdev_bsd_poll_cb(const struct rtbsd_change *change, void *aux)
+{
+    struct shash *arg = aux;
+    
+    if (change) {
+        struct list *dev_notifiers = shash_find_data(arg, change->if_name);
+        if (dev_notifiers) {
+            poll_notify(dev_notifiers);
+        }
+    } else {
+        struct shash_node *node;
+        SHASH_FOR_EACH (node, arg) {
+            poll_notify(node->data);
+        }
+    }
+}
+
+/*
+ * Arranges for 'cb' to be called whenever one of the attributes of
+ * 'netdev' changes and sets '*notifierp' to a newly created
+ * netdev_notifier that represents this arrangement.
+ *
+ * If the 'all_bsd_notifiers' is empty, it registers the
+ * 'netdev_bsd_poll_notifier'. Than it creates a new notifier and inserts it
+ * into the list belonging to the node in the 'all_bsd_notifiers' relative to
+ * the network device. In case it is the first notifier registered for this
+ * network device, it first create the node into the 'all_bsd_notifiers' and
+ * then appends the notifier to its list.
+ */
+static int
+netdev_bsd_poll_add(struct netdev *netdev,
+                      void (*cb)(struct netdev_notifier *), void *aux,
+                      struct netdev_notifier **notifierp)
+{
+    const char *netdev_name = netdev_get_name(netdev);
+    struct netdev_bsd_notifier *notifier;
+    struct list *list;
+
+    if (shash_is_empty(&all_bsd_notifiers)) {
+        /* This is the first time that this function is called so the main
+         * notifier needs to be registered */
+        int error = rtbsd_notifier_register(&netdev_bsd_poll_notifier,
+               netdev_bsd_poll_cb, &all_bsd_notifiers);
+        if (error) {
+            return error;
+        }
+    }
+    list = shash_find_data(&all_bsd_notifiers, netdev_name);
+    if (!list) {
+        list = xmalloc(sizeof *list);
+        list_init(list);
+        shash_add(&all_bsd_notifiers, netdev_name, list);
+    }
+
+    notifier = xmalloc(sizeof *notifier);
+    netdev_notifier_init(&notifier->notifier, netdev, cb, aux);
+    list_push_back(list, &notifier->node);
+    *notifierp = &notifier->notifier;
+    return 0;
+}
+
+static void
+netdev_bsd_poll_remove(struct netdev_notifier *notifier_)
+{
+    struct netdev_bsd_notifier *notifier =
+        CONTAINER_OF(notifier_, struct netdev_bsd_notifier, notifier);
+    struct list *list;
+
+    /* Remove 'notifier' from its list. */
+    list = list_remove(&notifier->node);
+    if (list_is_empty(list)) {
+        /* The list is now empty.  Remove it from the hash and free it. */
+        const char *netdev_name = netdev_get_name(notifier->notifier.netdev);
+        shash_delete(&all_bsd_notifiers,
+                     shash_find(&all_bsd_notifiers, netdev_name));
+        free(list);
+    }
+    free(notifier);
+
+    /* If that was the last notifier, unregister. */
+    if (shash_is_empty(&all_bsd_notifiers)) {
+        rtbsd_notifier_unregister(&netdev_bsd_poll_notifier);
+    }
+}
+
+const struct netdev_class netdev_bsd_class = {
+    "system",
+
+    netdev_bsd_init,
+    netdev_bsd_run,
+    netdev_bsd_wait,
+    netdev_bsd_create_system,
+    netdev_bsd_destroy,
+    NULL,  /* reconfigure */
+    netdev_bsd_open_system,
+    netdev_bsd_close,
+
+    netdev_bsd_enumerate,
+
+    netdev_bsd_recv,
+    netdev_bsd_recv_wait,
+    netdev_bsd_drain,
+
+    netdev_bsd_send,
+    netdev_bsd_send_wait,
+
+    netdev_bsd_set_etheraddr,
+    netdev_bsd_get_etheraddr,
+    netdev_bsd_get_mtu,
+    netdev_bsd_get_ifindex,
+    netdev_bsd_get_carrier,
+    netdev_bsd_get_stats,
+    NULL, /* set_stats */
+
+    netdev_bsd_get_features,
+    NULL, /* set_advertisement */
+    NULL, /* get_vlan_vid */  //XXX SIOCGETVLAN  
+    NULL, /* set_policing */
+    NULL, /* get_qos_type */
+    NULL, /* get_qos_capabilities */
+    NULL, /* get_qos */
+    NULL, /* set_qos */
+    NULL, /* get_queue */
+    NULL, /* set_queue */
+    NULL, /* delete_queue */
+    NULL, /* get_queue_stats */
+    NULL, /* dump_queue */
+    NULL, /* dump_queue_stats */
+
+    netdev_bsd_get_in4,
+    netdev_bsd_set_in4,
+    netdev_bsd_get_in6,
+    NULL, /* add_router */
+    NULL, /* get_next_hop */
+    NULL, /* arp_lookup */
+
+    netdev_bsd_update_flags,
+
+    netdev_bsd_poll_add,
+    netdev_bsd_poll_remove,
+};
+
+const struct netdev_class netdev_tap_class = {
+    "tap",  
+
+    netdev_bsd_init,
+    netdev_bsd_run,
+    netdev_bsd_wait,
+    netdev_bsd_create_tap,
+    netdev_bsd_destroy,
+    NULL,  /* reconfigure */
+    netdev_bsd_open_system,
+    netdev_bsd_close,
+
+    netdev_bsd_enumerate,
+
+    netdev_bsd_recv,
+    netdev_bsd_recv_wait,
+    netdev_bsd_drain,
+
+    netdev_bsd_send,
+    netdev_bsd_send_wait,
+
+    netdev_bsd_set_etheraddr,
+    netdev_bsd_get_etheraddr,
+    netdev_bsd_get_mtu,
+    netdev_bsd_get_ifindex,
+    netdev_bsd_get_carrier,
+    netdev_bsd_get_stats,
+    NULL, /* set_stats */
+
+    netdev_bsd_get_features,
+    NULL, /* set_advertisement */
+    NULL, /* get_vlan_vid */
+    NULL, /* set_policing */
+    NULL, /* get_qos_type */
+    NULL, /* get_qos_capabilities */
+    NULL, /* get_qos */
+    NULL, /* set_qos */
+    NULL, /* get_queue */
+    NULL, /* set_queue */
+    NULL, /* delete_queue */
+    NULL, /* get_queue_stats */
+    NULL, /* dump_queue */
+    NULL, /* dump_queue_stats */
+
+    netdev_bsd_get_in4,
+    netdev_bsd_set_in4,
+    netdev_bsd_get_in6,
+    NULL, /* add_router */
+    NULL, /* get_next_hop */
+    NULL, /* arp_lookup */
+
+    netdev_bsd_update_flags,
+
+    netdev_bsd_poll_add,
+    netdev_bsd_poll_remove,
+}; 
+
+
+static void 
+destroy_tap(int fd, const char *name)
+{
+    struct ifreq ifr;
+
+    close(fd);
+    strcpy(ifr.ifr_name, name);
+    /* XXX What to do if this call fails? */
+    ioctl(af_inet_sock, SIOCIFDESTROY, &ifr);
+}
+
+static int
+get_flags(const struct netdev *netdev, int *flags)
+{
+    struct ifreq ifr;
+    int error;
+    
+    error = netdev_bsd_do_ioctl(netdev, &ifr, SIOCGIFFLAGS, "SIOCGIFFLAGS");
+
+    *flags = 0xFFFF0000 & (ifr.ifr_flagshigh << 16);
+    *flags |= 0x0000FFFF & ifr.ifr_flags;
+
+    return error;
+}
+
+static int
+set_flags(struct netdev *netdev, int flags)
+{
+    struct ifreq ifr;
+
+    ifr.ifr_flags = 0x0000FFFF & flags;
+    ifr.ifr_flagshigh = (0xFFFF0000 & flags) >> 16;
+
+    return netdev_bsd_do_ioctl(netdev, &ifr, SIOCSIFFLAGS, "SIOCSIFFLAGS");
+}
+
+static int
+get_ifindex(const struct netdev *netdev_, int *ifindexp)
+{
+    struct netdev_dev_bsd *netdev_dev =
+                                netdev_dev_bsd_cast(netdev_get_dev(netdev_));
+    *ifindexp = 0;
+    if (!(netdev_dev->cache_valid & VALID_IFINDEX)) {
+        int ifindex = if_nametoindex(netdev_get_name(netdev_));
+        if (ifindex <= 0) {
+            return errno;
+        }
+        netdev_dev->cache_valid |= VALID_IFINDEX;
+        netdev_dev->ifindex = ifindex;
+    }
+    *ifindexp = netdev_dev->ifindex;
+    return 0;
+}
+
+static int
+get_etheraddr(const char *netdev_name, uint8_t ea[ETH_ADDR_LEN])
+{
+    struct ifaddrs *head;
+    struct ifaddrs *ifa;
+    struct sockaddr_dl *sdl;
+
+    if (getifaddrs(&head) != 0) {
+        VLOG_ERR("getifaddrs on %s device failed: %s", netdev_name, 
+                strerror(errno));
+        return errno;
+    }
+
+    for (ifa = head; ifa; ifa = ifa->ifa_next) {
+        if (ifa->ifa_addr->sa_family == AF_LINK) {
+            if (!strcmp(ifa->ifa_name, netdev_name)) {
+                sdl = (struct sockaddr_dl *)ifa->ifa_addr;
+                if (sdl) {
+                    memcpy(ea, LLADDR(sdl), sdl->sdl_alen);
+                    freeifaddrs(head);
+                    return 0;
+                }
+            }
+        }
+    }
+
+    VLOG_ERR("could not find ethernet address for %s device", netdev_name);
+    freeifaddrs(head);
+    return ENODEV;
+}
+
+static int
+set_etheraddr(const char *netdev_name, int hwaddr_family,
+              int hwaddr_len, const uint8_t mac[ETH_ADDR_LEN])
+{
+    struct ifreq ifr;
+    
+    memset(&ifr, 0, sizeof ifr);
+    strncpy(ifr.ifr_name, netdev_name, sizeof ifr.ifr_name);
+    ifr.ifr_addr.sa_family = hwaddr_family;
+    ifr.ifr_addr.sa_len = hwaddr_len;
+    memcpy(ifr.ifr_addr.sa_data, mac, hwaddr_len);
+    COVERAGE_INC(netdev_set_hwaddr);
+    if (ioctl(af_inet_sock, SIOCSIFLLADDR, &ifr) < 0) {
+        VLOG_ERR("ioctl(SIOCSIFLLADDR) on %s device failed: %s",
+                 netdev_name, strerror(errno));
+        return errno;
+    }
+    return 0;
+}
+
+static int
+netdev_bsd_do_ioctl(const struct netdev *netdev, struct ifreq *ifr,
+                    unsigned long cmd, const char *cmd_name)
+{
+    strncpy(ifr->ifr_name, netdev_get_name(netdev), sizeof ifr->ifr_name);
+    if (ioctl(af_inet_sock, cmd, ifr) == -1) {
+        VLOG_DBG_RL(&rl, "%s: ioctl(%s) failed: %s",
+                    netdev_get_name(netdev), cmd_name, strerror(errno));
+        return errno;
+    }
+    return 0;
+}
