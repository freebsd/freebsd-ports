--- ./skia/skia_common.gypi.orig	2014-08-12 21:03:06.000000000 +0200
+++ ./skia/skia_common.gypi	2014-08-13 09:56:58.000000000 +0200
@@ -66,7 +66,7 @@
     }],
 
     #Settings for text blitting, chosen to approximate the system browser.
-    [ 'OS == "linux"', {
+    [ 'OS == "linux" or os_bsd == 1', {
       'defines': [
         'SK_GAMMA_EXPONENT=1.2',
         'SK_GAMMA_CONTRAST=0.2',
