--- src/i830_driver.c.orig	2010-02-21 13:20:12.000000000 -0600
+++ src/i830_driver.c	2010-02-21 13:26:14.000000000 -0600
@@ -175,8 +175,6 @@
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
-#include "xf86RAC.h"
 #include "xf86Priv.h"
 #include "xf86cmap.h"
 #include "compiler.h"
@@ -1050,7 +1048,6 @@
    if (!xf86LoadSubModule(pScrn, "ddc")) {
       pI830->ddc2 = FALSE;
    } else {
-      xf86LoaderReqSymLists(I810ddcSymbols, NULL);
       pI830->ddc2 = TRUE;
    }
 
@@ -1058,8 +1055,6 @@
    /* Load I2C if we have the code to use it */
    if (pI830->ddc2) {
       if (xf86LoadSubModule(pScrn, "i2c")) {
-	 xf86LoaderReqSymLists(I810i2cSymbols, NULL);
-
 	 pI830->ddc2 = TRUE;
       } else {
 	 pI830->ddc2 = FALSE;
@@ -1511,11 +1506,9 @@
     /* The vgahw module should be loaded here when needed */
     if (!xf86LoadSubModule(pScrn, "vgahw"))
 	return FALSE;
-    xf86LoaderReqSymLists(I810vgahwSymbols, NULL);
 
     if (!xf86LoadSubModule(pScrn, "ramdac"))
        return FALSE;
-    xf86LoaderReqSymLists(I810ramdacSymbols, NULL);
 
     return TRUE;
 }
@@ -1854,12 +1847,6 @@
 			  pI830->PciInfo->func);
 #endif
 
-   if (xf86RegisterResources(pI830->pEnt->index, NULL, ResNone)) {
-      PreInitCleanup(pScrn);
-      return FALSE;
-   }
-
-   pScrn->racMemFlags = RAC_FB | RAC_COLORMAP;
    pScrn->monitor = pScrn->confScreen->monitor;
    pScrn->progClock = TRUE;
    pScrn->rgbBits = 8;
@@ -1942,8 +1929,6 @@
       return FALSE;
    }
 
-   xf86LoaderReqSymLists(I810fbSymbols, NULL);
-
    switch (pI830->accel) {
 #ifdef I830_USE_XAA
    case ACCEL_XAA:
@@ -1951,7 +1936,6 @@
 	 PreInitCleanup(pScrn);
 	 return FALSE;
       }
-      xf86LoaderReqSymLists(I810xaaSymbols, NULL);
       break;
 #endif
 
@@ -1973,7 +1957,6 @@
 	 PreInitCleanup(pScrn);
 	 return FALSE;
       }
-      xf86LoaderReqSymLists(I830exaSymbols, NULL);
       break;
    }
 #endif
@@ -1988,17 +1971,13 @@
 
        /*  We won't be using the VGA access after the probe. */
        I830SetMMIOAccess(pI830);
-       xf86SetOperatingState(resVgaIo, pI830->pEnt->index, ResUnusedOpr);
-       xf86SetOperatingState(resVgaMem, pI830->pEnt->index, ResDisableOpr);
    }
 
 #if defined(XF86DRI)
    /* Load the dri module if requested. */
    if (xf86ReturnOptValBool(pI830->Options, OPTION_DRI, FALSE) &&
        pI830->directRenderingType != DRI_DISABLED) {
-      if (xf86LoadSubModule(pScrn, "dri")) {
-	 xf86LoaderReqSymLists(I810driSymbols, I810drmSymbols, NULL);
-      }
+      xf86LoadSubModule(pScrn, "dri");
    }
 #endif
 
