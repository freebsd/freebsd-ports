--- programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c.orig	Tue Aug 24 17:30:41 2004
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c	Thu Jan 13 14:34:17 2005
@@ -4471,10 +4471,12 @@
 
     RADEONSave(pScrn);
 
-    if (xf86ReturnOptValBool(info->Options, OPTION_DYNAMIC_CLOCKS, FALSE)) {
-	RADEONSetDynamicClock(pScrn, 1);
-    } else {
-	RADEONSetDynamicClock(pScrn, 0);
+    if ((!info->IsSecondary) && info->IsMobility) {
+        if (xf86ReturnOptValBool(info->Options, OPTION_DYNAMIC_CLOCKS, FALSE)) {
+	    RADEONSetDynamicClock(pScrn, 1);
+        } else {
+	    RADEONSetDynamicClock(pScrn, 0);
+        }
     }
 
     if (info->FBDev) {
