--- src/nv_driver.c.orig	2017-01-17 22:41:33 UTC
+++ src/nv_driver.c
@@ -1543,7 +1543,11 @@ NVPreInit(ScrnInfoPtr pScrn, int flags)
 	xf86FreeInt10(pNv->pInt);
 	return FALSE;
     }
+#ifdef __powerpc__ /* XXX probably MI */
+    vgaHWSetMmioFuncs(VGAHWPTR(pScrn), pNv->IOAddress, 0);
+#else
     vgaHWSetStdFuncs(VGAHWPTR(pScrn));
+#endif
     
     /* We use a programmable clock */
     pScrn->progClock = TRUE;
