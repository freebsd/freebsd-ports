--- src/uct/tcp/tcp_iface.c.orig	2026-07-24 21:46:07 UTC
+++ src/uct/tcp/tcp_iface.c
@@ -20,6 +20,10 @@
 #include <netinet/tcp.h>
 #include <dirent.h>
 #include <float.h>
+#if defined(__FreeBSD__)
+#include <net/if.h>
+#include <net/if_types.h>
+#endif
 
 #define UCT_TCP_IFACE_NETDEV_DIR "/sys/class/net"
 
@@ -195,6 +199,41 @@ uct_tcp_iface_get_address(uct_iface_h tl_iface, uct_if
     return UCS_OK;
 }
 
+#if defined(__FreeBSD__)
+static int uct_tcp_iface_has_route(const struct sockaddr *addr)
+{
+    struct sockaddr_storage addr_copy;
+    socklen_t addrlen;
+    int fd, ret;
+
+    memcpy(&addr_copy, addr, sizeof(addr_copy));
+
+    if (addr->sa_family == AF_INET6) {
+        addrlen = sizeof(struct sockaddr_in6);
+        if (((struct sockaddr_in6*)&addr_copy)->sin6_port == 0) {
+            /* UDP connect() cannot target port 0; use a placeholder port
+             * since only route existence is being checked, not
+             * connectivity to a specific port. */
+            ((struct sockaddr_in6*)&addr_copy)->sin6_port = htons(1);
+        }
+    } else {
+        addrlen = sizeof(struct sockaddr_in);
+        if (((struct sockaddr_in*)&addr_copy)->sin_port == 0) {
+            ((struct sockaddr_in*)&addr_copy)->sin_port = htons(1);
+        }
+    }
+
+    fd = socket(addr->sa_family, SOCK_DGRAM, 0);
+    if (fd < 0) {
+        return 1; /* assume reachable if socket creation fails */
+    }
+
+    ret = connect(fd, (struct sockaddr*)&addr_copy, addrlen);
+    close(fd);
+    return (ret == 0);
+}
+#endif
+
 static int
 uct_tcp_iface_is_reachable_v2(const uct_iface_h tl_iface,
                               const uct_iface_is_reachable_params_t *params)
@@ -207,6 +246,9 @@ uct_tcp_iface_is_reachable_v2(const uct_iface_h tl_ifa
     char remote_addr_str[UCS_SOCKADDR_STRING_LEN];
     unsigned ndev_index;
     ucs_status_t status;
+#if defined(__FreeBSD__)
+    int is_best_route;
+#endif
 
     if (!uct_iface_is_reachable_params_valid(
                 params, UCT_IFACE_IS_REACHABLE_FIELD_DEVICE_ADDR)) {
@@ -264,8 +306,13 @@ uct_tcp_iface_is_reachable_v2(const uct_iface_h tl_ifa
         return 0;
     }
 
-    if (!ucs_netlink_is_best_route(ndev_index,
-                                   (const struct sockaddr*)&remote_addr)) {
+#if defined(__FreeBSD__)
+    is_best_route = uct_tcp_iface_has_route((const struct sockaddr*)&remote_addr);
+#else
+    int is_best_route = ucs_netlink_is_best_route(ndev_index,
+                                                  (const struct sockaddr*)&remote_addr);
+#endif
+    if (!is_best_route) {
         uct_iface_fill_info_str_buf(
                     params, "no route to %s",
                     ucs_sockaddr_str((const struct sockaddr *)&remote_addr,
@@ -284,6 +331,11 @@ uct_tcp_iface_get_sysfs_path(const char *dev_name, cha
 static const char *
 uct_tcp_iface_get_sysfs_path(const char *dev_name, char *path_buffer)
 {
+#if defined(__FreeBSD__)
+    (void)dev_name;
+    (void)path_buffer;
+    return NULL;
+#else
     const char *sysfs_path = NULL;
     ucs_status_t status;
     char *lowest_path_buf;
@@ -310,6 +362,7 @@ out:
     ucs_free(lowest_path_buf);
 out:
     return sysfs_path;
+#endif
 }
 
 static ucs_status_t uct_tcp_iface_query(uct_iface_h tl_iface,
@@ -422,7 +475,16 @@ static void uct_tcp_iface_handle_events(void *callback
     unsigned *count  = (unsigned*)arg;
     uct_tcp_ep_t *ep = (uct_tcp_ep_t*)callback_data;
 
+#if defined(__FreeBSD__)
+    /* kqueue may deliver a queued event for an ep that was closed and
+     * removed from the event set between the kevent() call and this
+     * callback.  Treat it as a no-op rather than aborting. */
+    if (ep->conn_state == UCT_TCP_EP_CONN_STATE_CLOSED) {
+        return;
+    }
+#else
     ucs_assertv(ep->conn_state != UCT_TCP_EP_CONN_STATE_CLOSED, "ep=%p", ep);
+#endif
 
     if (events & UCS_EVENT_SET_EVREAD) {
         *count += uct_tcp_ep_cm_state[ep->conn_state].rx_progress(ep);
@@ -943,6 +1005,10 @@ static int uct_tcp_is_bridge(const char *if_name)
 
 static int uct_tcp_is_bridge(const char *if_name)
 {
+#if defined(__FreeBSD__)
+    (void)if_name;
+    return 0;
+#else
     char *path;
     int ret;
     struct stat st;
@@ -962,6 +1028,7 @@ out:
     ucs_free(path);
 out:
     return ret;
+#endif
 }
 
 ucs_status_t uct_tcp_query_devices(uct_md_h md,
@@ -971,7 +1038,11 @@ ucs_status_t uct_tcp_query_devices(uct_md_h md,
     uct_tcp_md_t *tcp_md               = ucs_derived_of(md, uct_tcp_md_t);
     const unsigned sys_device_priority = 10;
     uct_tl_device_resource_t *devices, *tmp;
-    struct dirent **entries, **entry;
+#if defined(__FreeBSD__)
+    struct if_nameindex *ifn, *it;
+#else
+     struct dirent **entries, **entry;
+#endif
     unsigned num_devices;
     int is_active, i, n;
     ucs_status_t status;
@@ -979,21 +1050,77 @@ ucs_status_t uct_tcp_query_devices(uct_md_h md,
     char *path_buffer;
     ucs_sys_device_t sys_dev;
 
+#if defined(__FreeBSD__)
+    ifn = if_nameindex();
+    if (ifn == NULL) {
+        ucs_error("if_nameindex() failed: %m");
+        status = UCS_ERR_IO_ERROR;
+        goto out;
+    }
+#else
     n = scandir(UCT_TCP_IFACE_NETDEV_DIR, &entries, NULL, alphasort);
     if (n == -1) {
         ucs_error("scandir(%s) failed: %m", UCT_TCP_IFACE_NETDEV_DIR);
         status = UCS_ERR_IO_ERROR;
         goto out;
     }
+#endif
 
     devices     = NULL;
     num_devices = 0;
 
+#if defined(__FreeBSD__)
+    path_buffer = NULL;
+    status      = UCS_OK;
+#else
     status = ucs_string_alloc_path_buffer(&path_buffer, "path_buffer");
     if (status != UCS_OK) {
-        goto out;
+        goto out_release;
     }
+#endif
 
+#if defined(__FreeBSD__)
+    for (it = ifn; it->if_name != NULL; ++it) {
+        is_active = 0;
+        for (i = 0; i < tcp_md->config.af_prio_count; i++) {
+            if (ucs_netif_is_active(it->if_name,
+                                    tcp_md->config.af_prio_list[i])) {
+                is_active = 1;
+                break;
+            }
+        }
+
+        if (!is_active) {
+            continue;
+        }
+
+        if (!tcp_md->config.bridge_enable &&
+            uct_tcp_is_bridge(it->if_name)) {
+            ucs_debug("filtered out bridge device %s", it->if_name);
+            continue;
+        }
+
+        tmp = ucs_realloc(devices, sizeof(*devices) * (num_devices + 1),
+                          "tcp devices");
+        if (tmp == NULL) {
+            ucs_free(devices);
+            status = UCS_ERR_NO_MEMORY;
+            goto out_release;
+        }
+        devices = tmp;
+
+        sysfs_path = uct_tcp_iface_get_sysfs_path(it->if_name, path_buffer);
+        sys_dev    = ucs_topo_get_sysfs_dev(it->if_name, sysfs_path,
+                                            sys_device_priority);
+
+        ucs_snprintf_zero(devices[num_devices].name,
+                          sizeof(devices[num_devices].name), "%s",
+                          it->if_name);
+        devices[num_devices].type       = UCT_DEVICE_TYPE_NET;
+        devices[num_devices].sys_device = sys_dev;
+        ++num_devices;
+    }
+#else
     ucs_carray_for_each(entry, entries, n) {
         /* According to the sysfs(5) manual page, all of entries
          * has to be a symbolic link representing one of the real
@@ -1045,18 +1172,28 @@ ucs_status_t uct_tcp_query_devices(uct_md_h md,
         devices[num_devices].sys_device = sys_dev;
         ++num_devices;
     }
+#endif
 
     *num_devices_p = num_devices;
     *devices_p     = devices;
     status         = UCS_OK;
 
 out_release:
+#if defined(__FreeBSD__)
+    if (ifn != NULL) {
+        if_freenameindex(ifn);
+    }
+    if (path_buffer != NULL) {
+        ucs_free(path_buffer);
+    }
+#else
     ucs_carray_for_each(entry, entries, n) {
         free(*entry);
     }
 
     free(entries);
     ucs_free(path_buffer);
+#endif
 out:
     return status;
 }
