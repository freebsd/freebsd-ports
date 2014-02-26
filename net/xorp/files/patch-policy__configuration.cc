--- ./policy/configuration.cc.orig	2011-03-16 21:27:54.000000000 +0000
+++ ./policy/configuration.cc	2014-02-26 21:17:13.000000000 +0000
@@ -766,7 +766,9 @@
     POLICY* p = find_policy(proto);
     XLOG_ASSERT(p);
 
-    for (POLICY::reverse_iterator i = p->rbegin(); i != p->rend(); ++i) {
+//    for (POLICY::reverse_iterator i = p->rbegin(); i != p->rend(); ++i) {
+    if (! p->empty())
+    for (POLICY::iterator i = p->end(); --i != p->begin(); ) {
 	PolicyList* pl = i->second;
 
 	pl->link_code(code);
