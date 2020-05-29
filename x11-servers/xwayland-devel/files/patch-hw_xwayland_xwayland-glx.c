https://gitlab.freedesktop.org/xorg/xserver/-/issues/1032

--- hw/xwayland/xwayland-glx.c.orig	2020-05-20 07:13:28 UTC
+++ hw/xwayland/xwayland-glx.c
@@ -343,6 +343,9 @@ egl_screen_probe(ScreenPtr pScreen)
     struct xwl_screen *xwl_screen = xwl_screen_get(pScreen);
     __GLXscreen *base;
 
+    if (xwl_screen->egl_backend == &xwl_screen->eglstream_backend)
+        return NULL;
+
     if (enableIndirectGLX)
         return NULL; /* not implemented */
 
@@ -353,6 +356,7 @@ egl_screen_probe(ScreenPtr pScreen)
     base->destroy = egl_screen_destroy;
     base->createDrawable = egl_create_glx_drawable;
     /* base.swapInterval = NULL; */
+    base->glvnd = strdup("mesa");
 
     screen->display = xwl_screen->glamor_ctx->display;
 
