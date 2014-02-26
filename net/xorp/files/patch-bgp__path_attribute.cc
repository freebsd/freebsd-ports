--- ./bgp/path_attribute.cc.orig	2011-03-16 21:15:59.000000000 +0000
+++ ./bgp/path_attribute.cc	2014-02-26 21:17:13.000000000 +0000
@@ -830,8 +830,11 @@
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
