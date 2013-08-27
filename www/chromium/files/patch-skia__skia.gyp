--- skia/skia.gyp.orig	2013-08-18 20:57:26.000000000 +0300
+++ skia/skia.gyp	2013-08-18 21:08:51.000000000 +0300
@@ -284,7 +284,7 @@
           },
         }],
         #Settings for text blitting, chosen to approximate the system browser.
-        [ 'OS == "linux"', {
+        [ 'OS == "linux" or os_bsd == 1', {
           'defines': [
             'SK_GAMMA_EXPONENT=1.2',
             'SK_GAMMA_CONTRAST=0.2',
@@ -312,7 +312,7 @@
 
         # For POSIX platforms, prefer the Mutex implementation provided by Skia
         # since it does not generate static initializers.
-        [ 'OS == "android" or OS == "linux" or OS == "mac" or OS == "ios"', {
+        [ 'OS == "android" or OS == "linux" or OS == "mac" or OS == "ios" or os_bsd == 1', {
           'defines+': [
             'SK_USE_POSIX_THREADS',
           ],
