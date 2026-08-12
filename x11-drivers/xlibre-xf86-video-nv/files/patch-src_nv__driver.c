--- src/nv_driver.c.orig	2026-08-12 09:54:13 UTC
+++ src/nv_driver.c
@@ -1384,7 +1384,7 @@ NVPreInit(ScrnInfoPtr pScrn, int flags)
 	return FALSE;
     }
 #ifdef __powerpc__ /* XXX probably MI */
-    vgaHWSetMmioFuncs(VGAHWPTR(pScrn), pNv->IOAddress, 0);
+    vgaHWSetMmioFuncs(VGAHWPTR(pScrn), NULL, 0);
 #else
     vgaHWSetStdFuncs(VGAHWPTR(pScrn));
 #endif
