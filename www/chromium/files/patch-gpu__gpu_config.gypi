--- gpu/gpu_config.gypi.orig	2013-08-12 20:57:26.000000000 +0000
+++ gpu/gpu_config.gypi	2013-08-12 20:58:18.000000000 +0000
@@ -67,7 +67,7 @@
         '../third_party/amd/amd_videocard_info_win.cc',
       ],
     }],
-    ['OS=="linux" and use_x11==1', {
+    ['(OS=="linux" or os_bsd==1) and use_x11==1', {
       'dependencies': [
         '../build/linux/system.gyp:libpci',
         '../third_party/libXNVCtrl/libXNVCtrl.gyp:libXNVCtrl',
