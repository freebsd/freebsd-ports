--- skia/skia_common.gypi.orig	2014-10-10 08:54:17 UTC
+++ skia/skia_common.gypi
@@ -61,7 +61,7 @@
     }],
 
     #Settings for text blitting, chosen to approximate the system browser.
-    [ 'OS == "linux"', {
+    [ 'OS == "linux" or os_bsd == 1', {
       'defines': [
         'SK_GAMMA_EXPONENT=1.2',
         'SK_GAMMA_CONTRAST=0.2',
