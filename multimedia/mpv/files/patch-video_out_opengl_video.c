--- video/out/opengl/video.c.orig	2016-06-25 01:23:40 UTC
+++ video/out/opengl/video.c
@@ -881,7 +881,7 @@ static void uninit_video(struct gl_video
         gl->DeleteTextures(1, &plane->gl_texture);
         gl->DeleteBuffers(1, &plane->gl_buffer);
     }
-    *vimg = (struct video_image){0};
+    *vimg = (struct video_image){{{0}}};
 
     // Invalidate image_params to ensure that gl_video_config() will call
     // init_video() on uninitialized gl_video.
@@ -933,7 +933,7 @@ static void pass_prepare_src_tex(struct 
 static void render_pass_quad(struct gl_video *p, int vp_w, int vp_h,
                              const struct mp_rect *dst)
 {
-    struct vertex va[4] = {0};
+    struct vertex va[4] = {{{0}}};
 
     struct gl_transform t;
     gl_transform_ortho(&t, 0, vp_w, 0, vp_h);
@@ -2931,7 +2931,7 @@ static bool map_image(struct gl_video *p
 // This assumes nv12, with textures set to GL_NEAREST filtering.
 static void reinterleave_vdpau(struct gl_video *p, struct gl_hwdec_frame *frame)
 {
-    struct gl_hwdec_frame res = {0};
+    struct gl_hwdec_frame res = {{{0}}};
     for (int n = 0; n < 2; n++) {
         struct fbotex *fbo = &p->vdpau_deinterleave_fbo[n];
         // This is an array of the 2 to-merge planes.
@@ -2989,7 +2989,7 @@ static bool gl_video_upload_image(struct
 
     if (p->hwdec_active) {
         // Hardware decoding
-        struct gl_hwdec_frame gl_frame = {0};
+        struct gl_hwdec_frame gl_frame = {{{0}}};
         gl_timer_start(p->upload_timer);
         bool ok = p->hwdec->driver->map_frame(p->hwdec, vimg->mpi, &gl_frame) >= 0;
         gl_timer_stop(p->upload_timer);
