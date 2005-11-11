--- programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c.orig	Tue Nov  8 01:15:59 2005
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c	Tue Nov  8 01:15:37 2005
@@ -938,6 +938,9 @@ static RADEONMonitorType RADEONDisplayDD
 	MonType = MT_NONE;
     }
 
+    OUTREG(info->DDCReg, INREG(info->DDCReg) &
+	   ~(RADEON_GPIO_EN_0 | RADEON_GPIO_EN_1));
+
     if (*MonInfo) {
 	if ((*MonInfo)->rawData[0x14] & 0x80) {
 	    /* Note some laptops have a DVI output that uses internal TMDS,
@@ -2284,6 +2287,7 @@ static Bool RADEONPreInitConfig(ScrnInfo
     case PCI_CHIP_RV370_5464:
         info->IsMobility = TRUE;
     case PCI_CHIP_RV370_5B60:
+    case PCI_CHIP_RV370_5B62:
     case PCI_CHIP_RV370_5B64:
     case PCI_CHIP_RV370_5B65:
         info->ChipFamily = CHIP_FAMILY_RV380;
@@ -7159,7 +7163,6 @@ void RADEONAdjustFrame(int scrnIndex, in
 	RADEONDoAdjustFrame(pScrn, x, y, FALSE);
     }
 
-    RADEONSetFBLocation (pScrn);
 #ifdef XF86DRI
 	if (info->CPStarted) DRIUnlock(pScrn->pScreen);
 #endif
