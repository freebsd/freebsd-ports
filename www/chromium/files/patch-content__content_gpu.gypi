--- content/content_gpu.gypi.orig	2012-10-01 20:45:02.000000000 +0300
+++ content/content_gpu.gypi	2012-10-01 20:45:37.000000000 +0300
@@ -95,7 +95,7 @@
         '../third_party/amd/amd_videocard_info_win.cc',
       ],
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'dependencies': [
         '../third_party/libXNVCtrl/libXNVCtrl.gyp:libXNVCtrl',
       ],
