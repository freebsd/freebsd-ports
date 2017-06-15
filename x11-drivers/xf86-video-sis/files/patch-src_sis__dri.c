# Correct type in a format string
#
--- src/sis_dri.c.orig	2015-08-29 23:34:25 UTC
+++ src/sis_dri.c
@@ -454,7 +454,7 @@ SISDRIScreenInit(ScreenPtr pScreen)
      return FALSE;
   }
 
-  xf86DrvMsg(pScreen->myNum, X_INFO, "[drm] MMIO registers mapped to 0x%0x\n",
+  xf86DrvMsg(pScreen->myNum, X_INFO, "[drm] MMIO registers mapped to 0x%0lx\n",
 		pSISDRI->regs.handle);
 
   /* AGP */
