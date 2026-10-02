--- src/qxl_ums_mode.c.orig	2026-10-02 17:50:27 UTC
+++ src/qxl_ums_mode.c
@@ -63,7 +63,8 @@ qxl_add_mode (qxl_screen_t *qxl, ScrnInfoPtr pScrn, in
     DisplayModePtr mode;
 
     mode = screen_create_mode (pScrn, width, height, type);
-    pScrn->modes = qxl->x_modes = xf86ModesAdd (qxl->x_modes, mode);
+    qxl->x_modes = xf86ModesAdd (qxl->x_modes, mode);
+    pScrn->modes = xf86ModesAdd (pScrn->modes, xf86DuplicateMode (mode));
 
     return mode;
 }
