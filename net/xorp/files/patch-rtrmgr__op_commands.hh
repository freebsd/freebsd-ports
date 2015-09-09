--- rtrmgr/op_commands.hh.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/op_commands.hh
@@ -215,7 +215,7 @@ private:
 
     // Below here is temporary storage for use in parsing
     list<string>	_path_segments;
-    OpCommand*		_current_command;
+    // OpCommand*		_current_command;
     const TemplateTree*	_template_tree;
     SlaveConfigTree*	_slave_config_tree;
     SlaveModuleManager& _mmgr;
