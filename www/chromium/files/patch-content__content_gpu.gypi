--- content/content_gpu.gypi.orig	2012-11-28 04:01:27.000000000 +0200
+++ content/content_gpu.gypi	2012-12-04 22:06:17.000000000 +0200
@@ -95,7 +95,7 @@
         '../third_party/amd/amd_videocard_info_win.cc',
       ],
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or os_bsd==1', {
       'dependencies': [
         '../third_party/libXNVCtrl/libXNVCtrl.gyp:libXNVCtrl',
       ],
