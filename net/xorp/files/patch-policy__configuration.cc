--- policy/configuration.cc.orig	2012-01-11 17:56:10 UTC
+++ policy/configuration.cc
@@ -766,7 +766,9 @@ IEMap::link_code(const string& proto, Co
     POLICY* p = find_policy(proto);
     XLOG_ASSERT(p);
 
-    for (POLICY::reverse_iterator i = p->rbegin(); i != p->rend(); ++i) {
+//    for (POLICY::reverse_iterator i = p->rbegin(); i != p->rend(); ++i) {
+    if (! p->empty())
+    for (POLICY::iterator i = p->end(); --i != p->begin(); ) {
 	PolicyList* pl = i->second;
 
 	pl->link_code(code);
