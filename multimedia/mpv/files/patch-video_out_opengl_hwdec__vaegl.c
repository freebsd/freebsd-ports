--- video/out/opengl/hwdec_vaegl.c.orig	2016-06-25 10:09:55 UTC
+++ video/out/opengl/hwdec_vaegl.c
@@ -367,7 +367,7 @@ static bool test_format(struct gl_hwdec 
         va_surface_init_subformat(surface);
         struct mp_image_params params = surface->params;
         if (reinit(hw, &params) >= 0) {
-            struct gl_hwdec_frame frame = {0};
+            struct gl_hwdec_frame frame = {{{0}}};
             ok = map_frame(hw, surface, &frame) >= 0;
         }
         unmap_frame(hw);
