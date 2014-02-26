--- ./rtrmgr/template_tree_node.hh.orig	2011-03-16 21:16:14.000000000 +0000
+++ ./rtrmgr/template_tree_node.hh	2014-02-26 21:17:13.000000000 +0000
@@ -189,13 +189,15 @@
     TemplateTreeNode*	_parent;
     list<TemplateTreeNode*> _children;
 
+    TemplateTree&	_template_tree;
+
 private:
     bool split_up_varname(const string& varname,
 			  list<string>& var_parts) const;
     TemplateTreeNode* find_parent_varname_node(const list<string>& var_parts);
     TemplateTreeNode* find_child_varname_node(const list<string>& var_parts);
 
-    TemplateTree&	_template_tree;
+    // TemplateTree&	_template_tree;
 
     string _module_name;
     string _default_target_name;
