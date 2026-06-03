--- src/uct/ib/ud/base/ud_iface.c.orig	2026-02-05 12:41:56 UTC
+++ src/uct/ib/ud/base/ud_iface.c
@@ -1113,7 +1113,13 @@ union ibv_gid* uct_ud_grh_get_dgid(struct ibv_grh *grh
     size_t i;
 
     /* Make sure that daddr in IPv4 resides in the last 4 bytes in GRH */
-    UCS_STATIC_ASSERT((UCT_IB_GRH_LEN - (20 + offsetof(struct iphdr, daddr))) ==
+    UCS_STATIC_ASSERT((UCT_IB_GRH_LEN - (20 + offsetof(
+#if defined(__linux__)
+                          struct iphdr, daddr
+#else
+                          struct ip, ip_dst
+#endif
+                      ))) ==
                       UCS_IPV4_ADDR_LEN);
 
     /* Make sure that dgid resides in the last 16 bytes in GRH */
