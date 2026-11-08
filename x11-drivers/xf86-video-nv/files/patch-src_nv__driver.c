--- src/nv_driver.c.orig	2026-08-12 09:42:22 UTC
+++ src/nv_driver.c
@@ -1559,7 +1559,7 @@ NVPreInit(ScrnInfoPtr pScrn, int flags)
 	return FALSE;
     }
 #ifdef __powerpc__ /* XXX probably MI */
-    vgaHWSetMmioFuncs(VGAHWPTR(pScrn), pNv->IOAddress, 0);
+    vgaHWSetMmioFuncs(VGAHWPTR(pScrn), NULL, 0);
 #else
     vgaHWSetStdFuncs(VGAHWPTR(pScrn));
 #endif
