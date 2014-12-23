--- src/nv_driver.c.orig	2012-07-17 06:47:02 UTC
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
@@ -2550,7 +2554,6 @@ NVScreenInit(SCREEN_INIT_ARGS_DECL)
     if (!pNv->NoAccel)
 	NVAccelInit(pScreen);
     
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
