--- ./rtrmgr/op_commands.hh.orig	2011-03-16 21:27:56.000000000 +0000
+++ ./rtrmgr/op_commands.hh	2014-02-26 21:17:13.000000000 +0000
@@ -215,7 +215,7 @@
 
     // Below here is temporary storage for use in parsing
     list<string>	_path_segments;
-    OpCommand*		_current_command;
+    // OpCommand*		_current_command;
     const TemplateTree*	_template_tree;
     SlaveConfigTree*	_slave_config_tree;
     SlaveModuleManager& _mmgr;
