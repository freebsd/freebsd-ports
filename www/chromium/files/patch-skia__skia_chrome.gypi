--- skia/skia_chrome.gypi.orig	2015-10-14 18:24:42.938769000 +0200
+++ skia/skia_chrome.gypi	2015-10-14 18:22:24.515306000 +0200
@@ -60,6 +60,11 @@
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
