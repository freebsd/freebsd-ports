--- ./rtrmgr/template_tree_node.cc.orig	2011-03-16 21:16:14.000000000 +0000
+++ ./rtrmgr/template_tree_node.cc	2014-02-26 21:17:13.000000000 +0000
@@ -543,9 +543,12 @@
 {
     map<string,string> varmap;
     const TemplateTreeNode* ttn = this;
-    list<string>::const_reverse_iterator iter;
+    // list<string>::const_reverse_iterator iter;
+    list<string>::const_iterator iter;
 
-    for (iter = segments.rbegin(); iter != segments.rend(); ++iter) {
+//    for (iter = segments.rbegin(); iter != segments.rend(); ++iter) {
+    if (! segments.empty())
+    for (iter = segments.end(); iter-- != segments.begin(); ) {
 	if (ttn->name_is_variable())
 	    varmap[ttn->segname()] = *iter;
 	ttn = ttn->parent();
