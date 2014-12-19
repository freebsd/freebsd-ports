--- src/tdfx_driver.c.orig	2012-07-17 05:21:16 UTC
+++ src/tdfx_driver.c
@@ -62,10 +62,6 @@ SOFTWARE OR THE USE OR OTHER DEALINGS IN
 
 #include "compiler.h"
 
-/* Drivers using the mi implementation of backing store need: */
-
-#include "mibstore.h"
-
 /* All drivers using the vgahw module need this */
 /* This driver needs to be modified to not use vgaHW for multihead operation */
 #include "vgaHW.h"
@@ -2373,7 +2369,6 @@ TDFXScreenInit(SCREEN_INIT_ARGS_DECL) {
     }
   }
 
-  miInitializeBackingStore(pScreen);
   xf86SetBackingStore(pScreen);
   xf86SetSilkenMouse(pScreen);
 
