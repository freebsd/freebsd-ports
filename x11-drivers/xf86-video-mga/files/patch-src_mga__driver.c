# Correct a string that should be const
# Cast away a warning as done earlier in the same function
#
--- src/mga_driver.c.orig	2017-01-17 22:40:29 UTC
+++ src/mga_driver.c
@@ -1933,7 +1933,7 @@ MGAPreInit(ScrnInfoPtr pScrn, int flags)
     } else {
 	int from = X_DEFAULT;
 #ifdef USE_EXA
-	char *s = xf86GetOptValString(pMga->Options, OPTION_ACCELMETHOD);
+	const char *s = xf86GetOptValString(pMga->Options, OPTION_ACCELMETHOD);
 #endif
 	pMga->NoAccel = FALSE;
 	pMga->Exa = FALSE;
@@ -2644,7 +2644,7 @@ MGAMapMem(ScrnInfoPtr pScrn)
 	    err = pci_device_map_range(dev,
 				       region->base_addr, region->size,
 				       PCI_DEV_MAP_FLAG_WRITABLE,
-				       &pMga->IOBase);
+				       (void **)&pMga->IOBase);
 
 	    if (err) {
 	      xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
