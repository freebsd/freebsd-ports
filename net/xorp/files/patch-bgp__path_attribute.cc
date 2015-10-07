--- bgp/path_attribute.cc.orig	2012-01-11 17:56:10 UTC
+++ bgp/path_attribute.cc
@@ -45,18 +45,6 @@
 
 template<class A> AttributeManager<A>* PAListRef<A>::_att_mgr = 0;
 
-#ifdef DEBUG_LOGGING
-inline static void
-dump_bytes(const uint8_t* d, uint8_t l)
-{
-    for (uint16_t i = 0; i < l; i++) {
-	debug_msg("%3u 0x%02x\n", i, d[i]);
-    }
-}
-#else
-inline static void dump_bytes(const uint8_t*, uint8_t) {}
-#endif /* DEBUG_LOGGING */
-
 /*
  * Flags values crib:
  *
@@ -830,8 +818,11 @@ PathAttribute *
 ClusterListAttribute::clone() const
 {
     ClusterListAttribute *ca = new ClusterListAttribute();
-    list<IPv4>::const_reverse_iterator i = cluster_list().rbegin();
-    for(; i != cluster_list().rend(); i++)
+    // list<IPv4>::const_reverse_iterator i = cluster_list().rbegin();
+    list<IPv4>::const_iterator i = cluster_list().end();
+    if (! cluster_list().empty())
+    // for(; i != cluster_list().rend(); i++)
+    for(; i-- != cluster_list().begin(); )
 	ca->prepend_cluster_id(*i);
     return ca;
 }
