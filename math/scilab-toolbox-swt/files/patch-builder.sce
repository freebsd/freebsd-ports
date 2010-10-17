--- ./builder.sce.orig	2010-06-30 18:31:36.000000000 +0400
+++ ./builder.sce	2010-07-10 20:13:24.901709864 +0400
@@ -33,7 +33,7 @@
 tbx_builder_macros(toolbox_dir);
 //tbx_builder_src(toolbox_dir);
 tbx_builder_gateway(toolbox_dir);
-tbx_builder_help(toolbox_dir);
+// tbx_builder_help(toolbox_dir);
 tbx_build_loader(TOOLBOX_NAME, toolbox_dir);
 tbx_build_cleaner(TOOLBOX_NAME, toolbox_dir);
 
@@ -41,3 +41,5 @@
 // =============================================================================
 
 clear toolbox_dir TOOLBOX_NAME TOOLBOX_TITLE;
+
+quit
