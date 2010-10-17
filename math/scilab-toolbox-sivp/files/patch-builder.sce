--- ./builder.sce.orig	2010-01-31 15:21:14.000000000 +0300
+++ ./builder.sce	2010-07-10 19:24:17.021776380 +0400
@@ -33,7 +33,6 @@
 tbx_builder_macros(toolbox_dir);
 //tbx_builder_src(toolbox_dir);
 tbx_builder_gateway(toolbox_dir);
-tbx_builder_help(toolbox_dir);
 tbx_build_loader(TOOLBOX_NAME, toolbox_dir);
 tbx_build_cleaner(TOOLBOX_NAME, toolbox_dir);
 
@@ -41,3 +40,5 @@
 // =============================================================================
 
 clear toolbox_dir TOOLBOX_NAME TOOLBOX_TITLE;
+
+quit
