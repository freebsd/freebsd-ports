# Correct type in a format string
#
--- src/tdfx_dri.c.orig	2015-02-22 21:25:54 UTC
+++ src/tdfx_dri.c
@@ -454,7 +454,7 @@ Bool TDFXDRIScreenInit(ScreenPtr pScreen
     xf86DrvMsg(pScreen->myNum, X_ERROR, "drmAddMap failed, disabling DRI.\n");
     return FALSE;
   }
-  xf86DrvMsg(pScreen->myNum, X_INFO, "[drm] Registers = 0x%08x\n",
+  xf86DrvMsg(pScreen->myNum, X_INFO, "[drm] Registers = 0x%08lx\n",
 	       pTDFXDRI->regs);
 
   if (!(TDFXInitVisualConfigs(pScreen))) {
