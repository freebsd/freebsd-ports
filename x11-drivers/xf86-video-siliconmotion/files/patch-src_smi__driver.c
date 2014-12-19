--- src/smi_driver.c.orig	2012-07-17 04:53:21 UTC
+++ src/smi_driver.c
@@ -1750,8 +1750,6 @@ SMI_ScreenInit(SCREEN_INIT_ARGS_DECL)
 		   "Done writing mode.  Register dump:\n");
     SMI_PrintRegs(pScrn);
 
-    miInitializeBackingStore(pScreen);
-
 #ifdef HAVE_XMODES
     xf86DiDGAInit(pScreen, (unsigned long)(pSmi->FBBase + pScrn->fbOffset));
 #endif
