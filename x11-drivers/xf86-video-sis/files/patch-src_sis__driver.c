--- src/sis_driver.c.orig	2012-07-17 05:20:28 UTC
+++ src/sis_driver.c
@@ -57,7 +57,6 @@
 #include "fb.h"
 #include "micmap.h"
 #include "mipointer.h"
-#include "mibstore.h"
 #include "edid.h"
 
 #define SIS_NEED_inSISREG
@@ -8859,7 +8858,6 @@ SISScreenInit(SCREEN_INIT_ARGS_DECL)
     }
     pSiS->SiSFastVidCopyDone = TRUE;
 
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
@@ -9351,11 +9349,12 @@ SISMergedPointerMoved(SCRN_ARG_TYPE arg,
 	}
      }
      if(doit) {
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 20 /* screw it */
 	sigstate = xf86BlockSIGIO();
 #if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 15
         {
             double dx = x, dy = y;
-            miPointerSetPosition(inputInfo.pointer, Absolute, &dx, &dy);
+            miPointerSetPosition(inputInfo.pointer, Absolute, &dx, &dy, NULL, NULL);
             x = (int)dx;
             y = (int)dy;
         }
@@ -9368,6 +9367,7 @@ SISMergedPointerMoved(SCRN_ARG_TYPE arg,
 	miPointerAbsoluteCursor(x, y, currentTime.milliseconds);
 #endif
 	xf86UnblockSIGIO(sigstate);
+#endif
 	return;
      }
   }
