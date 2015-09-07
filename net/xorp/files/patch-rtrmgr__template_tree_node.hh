--- rtrmgr/template_tree_node.hh.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/template_tree_node.hh
@@ -189,13 +189,15 @@ protected:
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
