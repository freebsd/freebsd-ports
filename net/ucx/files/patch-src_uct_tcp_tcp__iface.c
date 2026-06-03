--- src/uct/tcp/tcp_iface.c.orig	2026-03-14 01:11:54 UTC
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
 
@@ -289,6 +293,11 @@ uct_tcp_iface_get_sysfs_path(const char *dev_name, cha
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
@@ -315,6 +324,7 @@ out:
     ucs_free(lowest_path_buf);
 out:
     return sysfs_path;
+#endif
 }
 
 static ucs_status_t uct_tcp_iface_query(uct_iface_h tl_iface,
@@ -948,6 +958,10 @@ static int uct_tcp_is_bridge(const char *if_name)
 
 static int uct_tcp_is_bridge(const char *if_name)
 {
+#if defined(__FreeBSD__)
+    (void)if_name;
+    return 0;
+#else
     char *path;
     int ret;
     struct stat st;
@@ -967,6 +981,7 @@ out:
     ucs_free(path);
 out:
     return ret;
+#endif
 }
 
 ucs_status_t uct_tcp_query_devices(uct_md_h md,
@@ -976,7 +991,11 @@ ucs_status_t uct_tcp_query_devices(uct_md_h md,
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
@@ -984,21 +1003,77 @@ ucs_status_t uct_tcp_query_devices(uct_md_h md,
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
@@ -1050,18 +1125,28 @@ ucs_status_t uct_tcp_query_devices(uct_md_h md,
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
