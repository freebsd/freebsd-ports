--- skia/skia_chrome.gypi.orig	2015-01-21 20:28:18 UTC
+++ skia/skia_chrome.gypi
@@ -87,6 +87,11 @@
     'ext/vector_platform_device_skia.h',
   ],
   'conditions': [
+    [ 'use_cairo == 1', {
+      'dependencies': [
+        '../build/linux/system.gyp:pangocairo',
+      ],
+    }],
     [ 'OS == "android" and '
       'enable_basic_printing==0 and enable_print_preview==0', {
       'sources!': [
