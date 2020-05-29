https://gitlab.freedesktop.org/xorg/xserver/-/issues/1032

--- hw/xwayland/xwayland-glx.c.orig	2020-05-20 07:13:28 UTC
+++ hw/xwayland/xwayland-glx.c
@@ -343,6 +343,10 @@ egl_screen_probe(ScreenPtr pScreen)
     struct xwl_screen *xwl_screen = xwl_screen_get(pScreen);
     __GLXscreen *base;
 
+#ifdef XWL_HAS_EGLSTREAM
+    return NULL;
+#endif
+
     if (enableIndirectGLX)
         return NULL; /* not implemented */
 
@@ -353,6 +357,9 @@ egl_screen_probe(ScreenPtr pScreen)
     base->destroy = egl_screen_destroy;
     base->createDrawable = egl_create_glx_drawable;
     /* base.swapInterval = NULL; */
+#ifndef XWL_HAS_EGLSTREAM
+    base->glvnd = strdup("mesa");
+#endif
 
     screen->display = xwl_screen->glamor_ctx->display;
 
