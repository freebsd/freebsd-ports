--- bgp/route_table_policy.cc.orig	2015-09-12 04:01:52.945569000 +0900
+++ bgp/route_table_policy.cc	2015-09-12 04:06:26.219083000 +0900
@@ -69,7 +69,7 @@
 			     bool no_modify) const
 {
     if (!_enable_filtering) {
-	return &rtmsg;
+	return true;
     }
 
     _varrw->attach_route(rtmsg, no_modify);
