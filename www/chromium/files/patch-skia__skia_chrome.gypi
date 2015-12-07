--- skia/skia_chrome.gypi.orig	2015-10-13 15:04:33.000000000 -0400
+++ skia/skia_chrome.gypi	2015-10-14 11:46:34.142959000 -0400
@@ -55,6 +55,11 @@
     'ext/skia_utils_win.cc',
   ],
   'conditions': [
+    [ 'use_cairo == 1', {
+      'dependencies': [
+        '../build/linux/system.gyp:pangocairo',
+      ],
+    }],
     [ 'OS == "ios"', {
       'sources!': [
         'ext/platform_canvas.cc',
