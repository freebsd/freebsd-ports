--- programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c.orig	Thu Feb 17 13:15:22 2005
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c	Thu Feb 17 13:21:09 2005
@@ -7159,7 +7159,6 @@
 	RADEONDoAdjustFrame(pScrn, x, y, FALSE);
     }
 
-    RADEONSetFBLocation (pScrn);
 #ifdef XF86DRI
 	if (info->CPStarted) DRIUnlock(pScrn->pScreen);
 #endif
