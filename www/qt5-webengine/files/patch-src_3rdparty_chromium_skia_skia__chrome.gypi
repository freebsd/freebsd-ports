--- src/3rdparty/chromium/skia/skia_chrome.gypi.orig	2017-04-20 12:39:06 UTC
+++ src/3rdparty/chromium/skia/skia_chrome.gypi
@@ -66,7 +66,7 @@
         'ext/skia_utils_base.cc',
       ],
     }],
-    [ 'OS != "android" and (OS != "linux" or use_cairo==1)', {
+    [ 'OS != "android" and ((OS != "linux" and os_bsd != 1) or use_cairo==1)', {
       'sources!': [
         'ext/bitmap_platform_device_skia.cc',
       ],
