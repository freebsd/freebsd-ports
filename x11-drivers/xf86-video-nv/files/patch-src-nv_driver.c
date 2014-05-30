--- src/nv_driver.c.orig	2014-01-19 15:24:45.000000000 -0600
+++ src/nv_driver.c	2014-01-19 15:24:07.000000000 -0600
@@ -1543,7 +1543,11 @@
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
