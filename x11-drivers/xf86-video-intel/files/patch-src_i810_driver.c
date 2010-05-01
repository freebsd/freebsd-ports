--- src/i810_driver.c.orig	2010-02-21 12:55:16.000000000 -0600
+++ src/i810_driver.c	2010-02-21 13:17:04.000000000 -0600
@@ -69,8 +69,6 @@
  */
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
-#include "xf86RAC.h"
 #include "xf86cmap.h"
 #include "compiler.h"
 #include "mibstore.h"
@@ -490,20 +488,6 @@
 		    );
 
       /*
-       * Tell the loader about symbols from other modules that this module
-       * might refer to.
-       */
-      LoaderRefSymLists(I810vgahwSymbols,
-			I810fbSymbols, I810xaaSymbols, I810ramdacSymbols,
-#ifdef XF86DRI
-			I810drmSymbols,
-			I810driSymbols,
-#endif
-			I810shadowFBSymbols,
-			I810vbeSymbols, vbeOptionalSymbols,
-			I810ddcSymbols, NULL);
-
-      /*
        * The return value must be non-NULL on success even though there
        * is no TearDownProc.
        */
@@ -809,7 +793,6 @@
    }
 
    if (xf86LoadSubModule(pScrn, "vbe") && (pVbe = VBEInit(NULL, index))) {
-      xf86LoaderReqSymLists(I810vbeSymbols, NULL);
       MonInfo = vbeDoEDID(pVbe, NULL);
       xf86PrintEDID(MonInfo);
       xf86SetDDCproperties(pScrn, MonInfo);
@@ -864,8 +847,6 @@
    if (!xf86LoadSubModule(pScrn, "vgahw"))
       return FALSE;
 
-   xf86LoaderReqSymLists(I810vgahwSymbols, NULL);
-
    /* Allocate a vgaHWRec */
    if (!vgaHWGetHWRec(pScrn))
       return FALSE;
@@ -878,10 +859,6 @@
 			  pI810->PciInfo->func);
 #endif
 
-   if (xf86RegisterResources(pI810->pEnt->index, NULL, ResNone))
-      return FALSE;
-   pScrn->racMemFlags = RAC_FB | RAC_COLORMAP;
-
    /* Set pScrn->monitor */
    pScrn->monitor = pScrn->confScreen->monitor;
 
@@ -960,7 +937,6 @@
 	 I810FreeRec(pScrn);
 	 return FALSE;
       }
-      xf86LoaderReqSymLists(I810xaaSymbols, NULL);
    }
    
 #ifdef XF86DRI
@@ -1244,14 +1220,12 @@
       I810FreeRec(pScrn);
       return FALSE;
    }
-   xf86LoaderReqSymLists(I810fbSymbols, NULL);
 
    if (!xf86ReturnOptValBool(pI810->Options, OPTION_SW_CURSOR, FALSE)) {
       if (!xf86LoadSubModule(pScrn, "ramdac")) {
 	 I810FreeRec(pScrn);
 	 return FALSE;
       }
-      xf86LoaderReqSymLists(I810ramdacSymbols, NULL);
    }
 
    if (xf86GetOptValInteger
@@ -1278,9 +1252,6 @@
 	 xf86DrvMsg(pScrn->scrnIndex, X_ERROR, 
 		    "Couldn't load shadowfb module:\n");
        }
-       else {
-	 xf86LoaderReqSymLists(I810shadowFBSymbols, NULL);
-       }
      }
      
      xf86DrvMsg(pScrn->scrnIndex, X_CONFIG, "page flipping %s\n",
@@ -1312,16 +1283,12 @@
 #ifdef XF86DRI
    /* Load the dri module if requested. */
    if (xf86ReturnOptValBool(pI810->Options, OPTION_DRI, FALSE)) {
-      if (xf86LoadSubModule(pScrn, "dri")) {
-	 xf86LoaderReqSymLists(I810driSymbols, I810drmSymbols, NULL);
-      }
+   	xf86LoadSubModule(pScrn, "dri");
    }
 #endif
 
    /*  We won't be using the VGA access after the probe */
    I810SetMMIOAccess(pI810);
-   xf86SetOperatingState(resVgaIo, pI810->pEnt->index, ResUnusedOpr);
-   xf86SetOperatingState(resVgaMem, pI810->pEnt->index, ResDisableOpr);
 
    return TRUE;
 }
