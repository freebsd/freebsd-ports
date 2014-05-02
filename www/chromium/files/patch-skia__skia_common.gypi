--- ./skia/skia_common.gypi.orig	2014-04-24 22:35:56.000000000 +0200
+++ ./skia/skia_common.gypi	2014-04-24 23:23:47.000000000 +0200
@@ -61,7 +61,7 @@
     }],
 
     #Settings for text blitting, chosen to approximate the system browser.
-    [ 'OS == "linux"', {
+    [ 'OS == "linux" or os_bsd == 1', {
       'defines': [
         'SK_GAMMA_EXPONENT=1.2',
         'SK_GAMMA_CONTRAST=0.2',
