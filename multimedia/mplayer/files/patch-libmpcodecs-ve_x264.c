--- libmpcodecs/ve_x264.c	Sun Mar 13 13:05:54 2005
+++ libmpcodecs/ve_x264.c.orig	Sun Mar 13 13:05:35 2005
@@ -49,7 +49,7 @@
 
 #include <x264.h>
 
-#if X264_BUILD < 0x000c
+#if X264_BUILD < 0x000e
 #error We do not support old versions of x264. Get the latest from SVN.
 #endif
 
@@ -138,8 +138,8 @@
     
     x264_param_default(&mod->param);
     mod->param.i_frame_reference = frame_ref;
-    mod->param.i_idrframe = idrframe;
-    mod->param.i_iframe = iframe;
+    mod->param.i_keyint_max = idrframe;
+    mod->param.i_keyint_min = iframe;
     mod->param.i_scenecut_threshold = scenecut_threshold;
     mod->param.i_bframe = bframe;
     mod->param.b_deblocking_filter = deblock;
