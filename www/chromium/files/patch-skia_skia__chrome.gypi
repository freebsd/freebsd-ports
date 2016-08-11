--- skia/skia_chrome.gypi.orig	2016-04-08 16:02:10 UTC
+++ skia/skia_chrome.gypi
@@ -61,6 +61,11 @@
         'ext/platform_canvas.cc',
       ],
     }],
+    [ 'use_cairo == 1', {
+      'dependencies': [
+        '../build/linux/system.gyp:pangocairo',
+      ],
+    }],
     [ 'OS == "android" and '
       'enable_basic_printing==0 and enable_print_preview==0', {
       'sources!': [
