--- src/via_driver.c.orig	2015-11-19 15:49:03.658837000 +0100
+++ src/via_driver.c	2015-11-19 15:51:11.689034000 +0100
@@ -806,7 +806,7 @@ via_xf86crtc_resize(ScrnInfoPtr scrn, in
 {
     xf86CrtcConfigPtr xf86_config = XF86_CRTC_CONFIG_PTR(scrn);
     struct buffer_object *old_front = NULL, *new_front = NULL;
-    int old_width, old_height, old_dwidth, format;
+    int old_width = 0, old_height = 0, old_dwidth = 0, format;
     int cpp = (scrn->bitsPerPixel + 7) >> 3, i;
     ScreenPtr screen = scrn->pScreen;
     VIAPtr pVia = VIAPTR(scrn);
