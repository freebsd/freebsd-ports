--- programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c.orig	Thu Feb 17 13:15:22 2005
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c	Thu Feb 17 13:21:09 2005
@@ -2501,6 +2501,7 @@
     case PCI_CHIP_RV370_5464:
         info->IsMobility = TRUE;
     case PCI_CHIP_RV370_5B60:
+    case PCI_CHIP_RV370_5B62:
     case PCI_CHIP_RV370_5B64:
     case PCI_CHIP_RV370_5B65:
         info->ChipFamily = CHIP_FAMILY_RV380;
@@ -7159,7 +7159,6 @@
 	RADEONDoAdjustFrame(pScrn, x, y, FALSE);
     }
 
-    RADEONSetFBLocation (pScrn);
 #ifdef XF86DRI
 	if (info->CPStarted) DRIUnlock(pScrn->pScreen);
 #endif
