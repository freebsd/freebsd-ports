--- skia/skia_library.gypi.orig	2013-09-03 22:15:35.743627150 +0300
+++ skia/skia_library.gypi	2013-09-03 22:17:46.187628519 +0300
@@ -214,7 +214,7 @@
     }],
 
     #Settings for text blitting, chosen to approximate the system browser.
-    [ 'OS == "linux"', {
+    [ 'OS == "linux" or os_bsd == 1', {
       'defines': [
         'SK_GAMMA_EXPONENT=1.2',
         'SK_GAMMA_CONTRAST=0.2',
@@ -242,7 +242,7 @@
 
     # For POSIX platforms, prefer the Mutex implementation provided by Skia
     # since it does not generate static initializers.
-    [ 'OS == "android" or OS == "linux" or OS == "mac" or OS == "ios"', {
+    [ 'os_posix == 1 or OS == "ios"', {
       'defines+': [
         'SK_USE_POSIX_THREADS',
       ],
