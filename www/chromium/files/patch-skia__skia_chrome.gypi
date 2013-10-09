--- skia/skia_chrome.gypi.orig	2013-09-24 22:30:33.000000000 +0300
+++ skia/skia_chrome.gypi	2013-09-24 22:29:39.000000000 +0300
@@ -85,7 +85,7 @@
     # For POSIX platforms, prefer the Mutex implementation provided by Skia
     # since it does not generate static initializers.
     # TODO: should check if SK_USE_POSIX_THREADS is defined instead
-    [ 'OS == "android" or OS == "linux" or OS == "mac" or OS == "ios"', {
+    [ 'OS == "android" or OS == "linux" or OS == "mac" or OS == "ios" or os_bsd == 1', {
       'sources!': [
         'ext/SkThread_chrome.cc',
       ],
