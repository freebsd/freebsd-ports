--- src/uct/base/uct_iface.c.orig	2026-06-18 20:00:16 UTC
+++ src/uct/base/uct_iface.c
@@ -1025,6 +1025,11 @@ int uct_iface_local_is_reachable(uct_iface_local_addr_
                                  ucs_sys_namespace_type_t sys_ns_type,
                                  const uct_iface_is_reachable_params_t *params)
 {
+#ifdef __FreeBSD__
+    /* On FreeBSD, local processes sharing loopback or IPC mechanisms
+     * are always mutually reachable. */
+    return 1;
+#else
     uct_iface_local_addr_ns_t my_addr = {};
 
     uct_iface_get_local_address(&my_addr, sys_ns_type);
@@ -1054,6 +1059,7 @@ int uct_iface_local_is_reachable(uct_iface_local_addr_
         return 0;
     }
     return 1;
+#endif
 }
 
 void uct_iface_mpool_config_copy(ucs_mpool_params_t *mp_params,
