# Correct types in a format string
#
--- src/savage_dri.c.orig	2017-01-17 22:43:40 UTC
+++ src/savage_dri.c
@@ -894,7 +894,7 @@ Bool SAVAGEDRIScreenInit( ScreenPtr pScr
    }
 
    xf86DrvMsg( pScrn->scrnIndex, X_INFO,
-	       "[drm] Sarea %d+%d: %d\n",
+	       "[drm] Sarea %lu+%lu: %lu\n",
 	       sizeof(XF86DRISAREARec), sizeof(SAVAGESAREAPrivRec),
 	       sizeof(XF86DRISAREARec) + sizeof(SAVAGESAREAPrivRec) );
 
