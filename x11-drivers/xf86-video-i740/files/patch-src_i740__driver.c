--- src/i740_driver.c.orig	2012-07-17 04:52:30 UTC
+++ src/i740_driver.c
@@ -63,10 +63,6 @@ SOFTWARE OR THE USE OR OTHER DEALINGS IN
 
 #include "compiler.h"
 
-/* Drivers using the mi implementation of backing store need: */
-
-#include "mibstore.h"
-
 /* All drivers using the vgahw module need this */
 /* This driver needs to be modified to not use vgaHW for multihead operation */
 #include "vgaHW.h"
@@ -1558,7 +1554,6 @@ I740ScreenInit(SCREEN_INIT_ARGS_DECL) {
     }
   }
 
-  miInitializeBackingStore(pScreen);
   xf86SetBackingStore(pScreen);
   xf86SetSilkenMouse(pScreen);
 
