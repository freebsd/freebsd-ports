https://gitlab.freedesktop.org/xorg/xserver/-/issues/1032

--- hw/xwayland/xwayland-glx.c.orig	2020-05-20 07:13:28 UTC
+++ hw/xwayland/xwayland-glx.c
@@ -354,6 +354,12 @@ egl_screen_probe(ScreenPtr pScreen)
     base->createDrawable = egl_create_glx_drawable;
     /* base.swapInterval = NULL; */
 
+    /* GlxVendorLibrary is queried in DRI2, so assume Mesa for now */
+    if (xwl_screen->egl_backend == &xwl_screen->eglstream_backend)
+        base->glvnd = strdup("nvidia");
+    else
+        base->glvnd = strdup("mesa");
+
     screen->display = xwl_screen->glamor_ctx->display;
 
     __glXInitExtensionEnableBits(screen->base.glx_enable_bits);
