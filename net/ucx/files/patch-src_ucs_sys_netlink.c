--- src/ucs/sys/netlink.c.orig	2026-05-06 13:47:14 UTC
+++ src/ucs/sys/netlink.c
@@ -8,6 +8,8 @@
 #include "config.h"
 #endif
 
+#if defined(__linux__)
+
 #include "netlink.h"
 
 #include <ucs/datastruct/khash.h>
@@ -347,3 +349,80 @@ int ucs_netlink_is_best_route(int if_index, const stru
 
     return (ucs_netlink_max_netmask_len(sa_remote) == netmask_len);
 }
+#else
+
+#include "netlink.h"
+
+#include <ucs/sys/sock.h>
+
+#include <net/if.h>
+#include <sys/ioctl.h>
+#include <netinet/in.h>
+#include <string.h>
+
+ucs_status_t
+ucs_netlink_send_request(int protocol, unsigned short nlmsg_type,
+                         unsigned short nlmsg_flags,
+                         const void *protocol_header, size_t header_length,
+                         ucs_netlink_parse_cb_t parse_cb, void *arg)
+{
+    (void)protocol;
+    (void)nlmsg_type;
+    (void)nlmsg_flags;
+    (void)protocol_header;
+    (void)header_length;
+    (void)parse_cb;
+    (void)arg;
+    return UCS_ERR_UNSUPPORTED;
+}
+
+int
+ucs_netlink_route_exists(int if_index, const struct sockaddr *sa_remote,
+                         int *netmask_len_p)
+{
+    char if_name[IF_NAMESIZE];
+    struct ifreq ifr;
+    struct sockaddr_in local_addr, netmask;
+    in_addr_t local_ip, mask, remote_ip;
+
+    if (sa_remote->sa_family != AF_INET) {
+        return 0; /* IPv6 not yet handled */
+    }
+
+    if (if_indextoname(if_index, if_name) == NULL) {
+        return 0;
+    }
+
+    memset(&ifr, 0, sizeof(ifr));
+    if (ucs_netif_ioctl(if_name, SIOCGIFADDR, &ifr) != UCS_OK) {
+        return 0;
+    }
+    memcpy(&local_addr, &ifr.ifr_addr, sizeof(local_addr));
+
+    memset(&ifr, 0, sizeof(ifr));
+    if (ucs_netif_ioctl(if_name, SIOCGIFNETMASK, &ifr) != UCS_OK) {
+        return 0;
+    }
+    memcpy(&netmask, &ifr.ifr_addr, sizeof(netmask));
+
+    local_ip  = local_addr.sin_addr.s_addr;
+    mask      = netmask.sin_addr.s_addr;
+    remote_ip = ((const struct sockaddr_in *)sa_remote)->sin_addr.s_addr;
+
+    if (netmask_len_p != NULL) {
+        *netmask_len_p = __builtin_popcount(ntohl(mask));
+    }
+
+    /* Remote is reachable if it is in the same subnet as the local interface */
+    return (remote_ip & mask) == (local_ip & mask);
+}
+
+int
+ucs_netlink_is_best_route(int if_index, const struct sockaddr *sa_remote)
+{
+    int netmask_len;
+
+    return ucs_netlink_route_exists(if_index, sa_remote, &netmask_len);
+}
+
+#endif
