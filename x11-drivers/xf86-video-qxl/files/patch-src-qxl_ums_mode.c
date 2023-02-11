--- src/qxl_ums_mode.c.orig	2023-01-07 21:22:08 UTC
+++ src/qxl_ums_mode.c
@@ -65,7 +65,7 @@ qxl_add_mode (qxl_screen_t *qxl, ScrnInfoPtr pScrn, in
     DisplayModePtr mode;
 
     mode = screen_create_mode (pScrn, width, height, type);
-    qxl->x_modes = xf86ModesAdd (qxl->x_modes, mode);
+    pScrn->modes = qxl->x_modes = xf86ModesAdd (qxl->x_modes, mode);
 
     return mode;
 }
