--- src/tseng_driver.c.orig	2012-07-17 05:21:17 UTC
+++ src/tseng_driver.c
@@ -39,9 +39,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 #include "fb.h"
 
 #if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 6
@@ -1453,7 +1450,6 @@ TsengScreenInit(SCREEN_INIT_ARGS_DECL)
 	}
     }
 
-    miInitializeBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
     /* Initialise cursor functions */
     miDCInitialize(pScreen, xf86GetPointerScreenFuncs());
