--- skia/skia_chrome.gypi.orig	2014-10-02 17:39:48 UTC
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
     [ 'OS == "android" and enable_printing == 0', {
       'sources!': [
         'ext/skia_utils_base.cc',
