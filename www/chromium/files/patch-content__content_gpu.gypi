--- content/content_gpu.gypi.orig	2013-05-13 01:34:00.000000000 +0000
+++ content/content_gpu.gypi	2013-05-16 23:23:49.000000000 +0000
@@ -85,7 +85,7 @@
         '../third_party/amd/amd_videocard_info_win.cc',
       ],
     }],
-    ['OS=="linux" and use_x11==1', {
+    ['(OS=="linux" and use_x11==1) or os_bsd==1', {
       'dependencies': [
         '../build/linux/system.gyp:libpci',
         '../third_party/libXNVCtrl/libXNVCtrl.gyp:libXNVCtrl',
