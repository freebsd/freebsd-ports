--- ./gpu/gpu_config.gypi.orig	2014-08-12 21:01:10.000000000 +0200
+++ ./gpu/gpu_config.gypi	2014-08-13 09:56:57.000000000 +0200
@@ -63,7 +63,7 @@
         '../third_party/amd/amd_videocard_info_win.cc',
       ],
     }],
-    ['OS=="linux" and use_x11==1', {
+    ['(OS=="linux" or os_bsd==1) and use_x11==1', {
       'dependencies': [
         '../build/linux/system.gyp:x11',
         '../build/linux/system.gyp:xext',
