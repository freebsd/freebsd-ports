--- video/out/opengl/video.c.orig	2016-04-12 22:17:16 UTC
+++ video/out/opengl/video.c
@@ -1003,7 +1003,7 @@ static void pass_prepare_src_tex(struct 
 static void render_pass_quad(struct gl_video *p, int vp_w, int vp_h,
                              const struct mp_rect *dst)
 {
-    struct vertex va[4] = {0};
+    struct vertex va[4] = {{{0}}};
 
     struct gl_transform t;
     gl_transform_ortho(&t, 0, vp_w, 0, vp_h);
