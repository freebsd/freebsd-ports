--- rtrmgr/template_tree_node.cc.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/template_tree_node.cc
@@ -543,9 +543,12 @@ TemplateTreeNode::create_variable_map(co
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
