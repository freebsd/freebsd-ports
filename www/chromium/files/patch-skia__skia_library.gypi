--- skia/skia_library.gypi.orig	2013-09-03 22:15:35.743627150 +0300
+++ skia/skia_library.gypi	2013-09-03 22:17:46.187628519 +0300
@@ -193,7 +193,7 @@
     }],
 
     #Settings for text blitting, chosen to approximate the system browser.
-    [ 'OS == "linux"', {
+    [ 'OS == "linux" or os_bsd == 1', {
       'defines': [
         'SK_GAMMA_EXPONENT=1.2',
         'SK_GAMMA_CONTRAST=0.2',
