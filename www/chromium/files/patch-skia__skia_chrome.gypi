--- ./skia/skia_chrome.gypi.orig	2014-08-20 21:03:15.000000000 +0200
+++ ./skia/skia_chrome.gypi	2014-08-22 15:06:26.000000000 +0200
@@ -80,6 +80,11 @@
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
