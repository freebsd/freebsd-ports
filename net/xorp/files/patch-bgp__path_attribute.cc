--- bgp/path_attribute.cc.orig	2012-01-11 17:56:10 UTC
+++ bgp/path_attribute.cc
@@ -830,8 +830,11 @@ PathAttribute *
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
