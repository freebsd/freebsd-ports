# two upstream clean-up commits plus a string const fix
#
--- src/i128_driver.c.orig	2012-07-17 05:21:15 UTC
+++ src/i128_driver.c
@@ -50,12 +50,9 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
 #include "micmap.h"
 
 #include "xf86DDC.h"
-#include "vbe.h"
 
 #include "xf86cmap.h"
 #include "fb.h"
@@ -586,7 +583,7 @@ I128PreInit(ScrnInfoPtr pScrn, int flags
 	xf86DrvMsg(pScrn->scrnIndex, X_CONFIG, "Acceleration disabled\n");
     } else {
         int from = X_DEFAULT;
-        char *s = xf86GetOptValString(pI128->Options, OPTION_ACCELMETHOD);
+        const char *s = xf86GetOptValString(pI128->Options, OPTION_ACCELMETHOD);
         pI128->NoAccel = FALSE;
         if (!xf86NameCmp(s, "EXA")) {
             pI128->exa = TRUE;
@@ -1557,7 +1554,6 @@ I128ScreenInit(SCREEN_INIT_ARGS_DECL)
         return FALSE;
     }
     
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
