--- libmpcodecs/ve_x264.c.orig	Tue Nov 23 19:54:20 2004
+++ libmpcodecs/ve_x264.c	Thu Apr 21 08:31:22 2005
@@ -49,10 +49,6 @@
 
 #include <x264.h>
 
-#if X264_BUILD < 0x000c
-#error We do not support old versions of x264. Get the latest from SVN.
-#endif
-
 typedef struct _h264_module_t {
     muxer_stream_t *mux;
     x264_param_t    param;
@@ -65,20 +61,28 @@
 static int bitrate = -1;
 static int qp_constant = 26;
 static int frame_ref = 1;
-static int iframe = 250;
-static int idrframe = 2;
+static int keyint_max = 250;
+static int keyint_min = -1;
 static int scenecut_threshold = 40;
 static int bframe = 0;
+static int bframe_adaptive = 1;
+static int bframe_bias = 0;
+static int bframe_pyramid = 0;
 static int deblock = 1;
 static int deblockalpha = 0;
 static int deblockbeta = 0;
 static int cabac = 1;
-static int cabacidc = -1;
 static int p4x4mv = 0;
+static int p8x8mv = 1;
+static int b8x8mv = 1;
+static int direct_pred = X264_DIRECT_PRED_TEMPORAL;
+static int weight_b = 0;
+static int chroma_me = 1;
+static int chroma_qp_offset = 0;
 static float ip_factor = 1.4;
-static float pb_factor = 1.4;
+static float pb_factor = 1.3;
 static int rc_buffer_size = -1;
-static int rc_init_buffer = -1;
+static float rc_init_buffer = 0.25;
 static int rc_sens = 4;
 static int qp_min = 10;
 static int qp_max = 51;
@@ -87,48 +91,66 @@
 static float qcomp = 0.6;
 static float qblur = 0.5;
 static float complexity_blur = 20;
-static char *rc_eq = "tex*blurTex^(qComp-1)";
-static int subq = 1;
+static char *rc_eq = "blurCplx^(1-qComp)";
+static int subq = 5;
+static int level_idc = 40;
 static int psnr = 0;
 static int log_level = 2;
 
 m_option_t x264encopts_conf[] = {
     {"bitrate", &bitrate, CONF_TYPE_INT, CONF_RANGE, 0, 24000000, NULL},
     {"qp_constant", &qp_constant, CONF_TYPE_INT, CONF_RANGE, 1, 51, NULL},
-    {"frameref", &frame_ref, CONF_TYPE_INT, CONF_RANGE, 1, 15, NULL},
-    {"keyint", &iframe, CONF_TYPE_INT, CONF_RANGE, 1, 24000000, NULL},
-    {"idrint", &idrframe, CONF_TYPE_INT, CONF_RANGE, 1, 24000000, NULL},
+    {"frameref", &frame_ref, CONF_TYPE_INT, CONF_RANGE, 1, 16, NULL},
+    {"keyint", &keyint_max, CONF_TYPE_INT, CONF_RANGE, 1, 24000000, NULL},
+    {"keyint_min", &keyint_min, CONF_TYPE_INT, CONF_RANGE, 1, 24000000, NULL},
     {"scenecut", &scenecut_threshold, CONF_TYPE_INT, CONF_RANGE, -1, 100, NULL},
     {"bframes", &bframe, CONF_TYPE_INT, CONF_RANGE, 0, 16, NULL},
+    {"b_adapt", &bframe_adaptive, CONF_TYPE_FLAG, 0, 0, 1, NULL},
+    {"nob_adapt", &bframe_adaptive, CONF_TYPE_FLAG, 0, 1, 0, NULL},
+    {"b_bias", &bframe_bias, CONF_TYPE_INT, CONF_RANGE, -100, 100, NULL},
+    {"b_pyramid", &bframe_pyramid, CONF_TYPE_FLAG, 0, 0, 1, NULL},
+    {"nob_pyramid", &bframe_pyramid, CONF_TYPE_FLAG, 0, 1, 0, NULL},
     {"deblock", &deblock, CONF_TYPE_FLAG, 0, 0, 1, NULL},
     {"nodeblock", &deblock, CONF_TYPE_FLAG, 0, 1, 0, NULL},
     {"deblockalpha", &deblockalpha, CONF_TYPE_INT, CONF_RANGE, -6, 6, NULL},
     {"deblockbeta", &deblockbeta, CONF_TYPE_INT, CONF_RANGE, -6, 6, NULL},
     {"cabac", &cabac, CONF_TYPE_FLAG, 0, 0, 1, NULL},
     {"nocabac", &cabac, CONF_TYPE_FLAG, 0, 1, 0, NULL},
-    {"cabacidc", &cabacidc, CONF_TYPE_INT, CONF_RANGE, -1, 2, NULL},
     {"4x4mv", &p4x4mv, CONF_TYPE_FLAG, 0, 0, 1, NULL},
     {"no4x4mv", &p4x4mv, CONF_TYPE_FLAG, 0, 1, 0, NULL},
+    {"8x8mv", &p8x8mv, CONF_TYPE_FLAG, 0, 0, 1, NULL},
+    {"no8x8mv", &p8x8mv, CONF_TYPE_FLAG, 0, 1, 0, NULL},
+    {"b8x8mv", &b8x8mv, CONF_TYPE_FLAG, 0, 0, 1, NULL},
+    {"nob8x8mv", &b8x8mv, CONF_TYPE_FLAG, 0, 1, 0, NULL},
+    {"direct_pred", &direct_pred, CONF_TYPE_INT, CONF_RANGE, 0, 2, NULL},
+    {"weight_b", &weight_b, CONF_TYPE_FLAG, 0, 0, 1, NULL},
+    {"noweight_b", &weight_b, CONF_TYPE_FLAG, 0, 1, 0, NULL},
+    {"chroma_me", &chroma_me, CONF_TYPE_FLAG, 0, 0, 1, NULL},
+    {"nochroma_me", &chroma_me, CONF_TYPE_FLAG, 0, 1, 0, NULL},
+    {"chroma_qp_offset", &chroma_qp_offset, CONF_TYPE_INT, CONF_RANGE, -12, 12, NULL},
     {"ip_factor", &ip_factor, CONF_TYPE_FLOAT, CONF_RANGE, -10.0, 10.0, NULL},
     {"pb_factor", &pb_factor, CONF_TYPE_FLOAT, CONF_RANGE, -10.0, 10.0, NULL},
     {"rc_buffer_size", &rc_buffer_size, CONF_TYPE_INT, CONF_RANGE, 0, 24000000, NULL},
-    {"rc_init_buffer", &rc_init_buffer, CONF_TYPE_INT, CONF_RANGE, 0, 24000000, NULL},
+    {"rc_init_buffer", &rc_init_buffer, CONF_TYPE_FLOAT, CONF_RANGE, 0, 24000000, NULL},
     {"rc_sens", &rc_sens, CONF_TYPE_INT, CONF_RANGE, 0, 100, NULL},
     {"qp_min", &qp_min, CONF_TYPE_INT, CONF_RANGE, 1, 51, NULL},
     {"qp_max", &qp_max, CONF_TYPE_INT, CONF_RANGE, 1, 51, NULL},
-    {"qp_step", &qp_step, CONF_TYPE_INT, CONF_RANGE, 0, 50, NULL},
+    {"qp_step", &qp_step, CONF_TYPE_INT, CONF_RANGE, 1, 50, NULL},
     {"pass", &pass, CONF_TYPE_INT, CONF_RANGE, 1, 3, NULL},
     {"rc_eq", &rc_eq, CONF_TYPE_STRING, 0, 0, 0, NULL},
     {"qcomp", &qcomp, CONF_TYPE_FLOAT, CONF_RANGE, 0, 1, NULL},
     {"qblur", &qblur, CONF_TYPE_FLOAT, CONF_RANGE, 0, 99, NULL},
     {"cplx_blur", &complexity_blur, CONF_TYPE_FLOAT, CONF_RANGE, 0, 999, NULL},
-    {"subq", &subq, CONF_TYPE_INT, CONF_RANGE, 0, 5, NULL},
+    {"subq", &subq, CONF_TYPE_INT, CONF_RANGE, 1, 5, NULL},
+    {"level_idc", &level_idc, CONF_TYPE_INT, CONF_RANGE, 10, 51, NULL},
     {"psnr", &psnr, CONF_TYPE_FLAG, 0, 0, 1, NULL},
     {"nopsnr", &psnr, CONF_TYPE_FLAG, 0, 1, 0, NULL},
     {"log", &log_level, CONF_TYPE_INT, CONF_RANGE, -1, 3, NULL},
     {NULL, NULL, 0, 0, 0, 0, NULL}
 };
-    
+
+static int put_image(struct vf_instance_s *vf, mp_image_t *mpi);
+static int encode_frame(struct vf_instance_s *vf, x264_picture_t *pic_in);
 
 static int config(struct vf_instance_s* vf, int width, int height, int d_width, int d_height, unsigned int flags, unsigned int outfmt) {
     h264_module_t *mod=(h264_module_t*)vf->priv;
@@ -138,15 +160,17 @@
     
     x264_param_default(&mod->param);
     mod->param.i_frame_reference = frame_ref;
-    mod->param.i_idrframe = idrframe;
-    mod->param.i_iframe = iframe;
+    mod->param.i_keyint_max = keyint_max;
+    mod->param.i_keyint_min = keyint_min > 0 ? keyint_min : keyint_max * 2 / 5;
     mod->param.i_scenecut_threshold = scenecut_threshold;
     mod->param.i_bframe = bframe;
+    mod->param.b_bframe_adaptive = bframe_adaptive;
+    mod->param.i_bframe_bias = bframe_bias;
+    mod->param.b_bframe_pyramid = bframe_pyramid;
     mod->param.b_deblocking_filter = deblock;
     mod->param.i_deblocking_filter_alphac0 = deblockalpha;
     mod->param.i_deblocking_filter_beta = deblockbeta;
     mod->param.b_cabac = cabac;
-    mod->param.i_cabac_init_idc = cabacidc;
 
     mod->param.rc.i_qp_constant = qp_constant;
     if(qp_min > qp_constant)
@@ -190,23 +214,34 @@
     if(bitrate > 0) {
         if(rc_buffer_size <= 0)
             rc_buffer_size = bitrate;
-        if(rc_init_buffer < 0)
-            rc_init_buffer = rc_buffer_size/4;
         mod->param.rc.b_cbr = 1;
         mod->param.rc.i_bitrate = bitrate;
         mod->param.rc.i_rc_buffer_size = rc_buffer_size;
-        mod->param.rc.i_rc_init_buffer = rc_init_buffer;
+        if(rc_init_buffer > 1)
+            mod->param.rc.i_rc_init_buffer = rc_init_buffer;
+        else
+            mod->param.rc.i_rc_init_buffer = rc_buffer_size * rc_init_buffer;
         mod->param.rc.i_rc_sens = rc_sens;
     }
-    if(p4x4mv)
-        mod->param.analyse.inter = X264_ANALYSE_I4x4 | X264_ANALYSE_PSUB16x16 | X264_ANALYSE_PSUB8x8;
     mod->param.rc.f_ip_factor = ip_factor;
     mod->param.rc.f_pb_factor = pb_factor;
+    mod->param.analyse.inter = X264_ANALYSE_I4x4;
+    if(p4x4mv)
+        mod->param.analyse.inter |= X264_ANALYSE_PSUB8x8;
+    if(p8x8mv)
+        mod->param.analyse.inter |= X264_ANALYSE_PSUB16x16;
+    if(b8x8mv)
+        mod->param.analyse.inter |= X264_ANALYSE_BSUB16x16;
+    mod->param.analyse.i_direct_mv_pred = direct_pred;
+    mod->param.analyse.b_weighted_bipred = weight_b;
+    mod->param.analyse.i_chroma_qp_offset = chroma_qp_offset;
+    mod->param.analyse.b_chroma_me = chroma_me;
 
     mod->param.i_width = width;
     mod->param.i_height = height;
     mod->param.i_fps_num = mod->mux->h.dwRate;
     mod->param.i_fps_den = mod->mux->h.dwScale;
+    mod->param.i_level_idc = level_idc;
     mod->param.analyse.b_psnr = psnr;
     mod->param.i_log_level = log_level;
     mod->param.vui.i_sar_width = d_width*height;
@@ -256,13 +291,19 @@
         return 0;
     }
     
-    x264_picture_alloc(&mod->pic, mod->param.i_csp, mod->param.i_width, mod->param.i_height);
     return 1;
 }
 
 static int control(struct vf_instance_s* vf, int request, void *data)
 {
-    return CONTROL_UNKNOWN;
+    switch(request){
+        case VFCTRL_FLUSH_FRAMES:
+            if(bframe)
+                while(encode_frame(vf, NULL) > 0);
+            return CONTROL_TRUE;
+        default:
+            return CONTROL_UNKNOWN;
+    }
 }
 
 static int query_format(struct vf_instance_s* vf, unsigned int fmt)
@@ -277,9 +318,8 @@
     case IMGFMT_RGB:
     case IMGFMT_BGR:
     case IMGFMT_BGR32:
-        /* 2004/08/05: There seems to be some, but not complete,
-           support for these colorspaces in X264. Better to stay
-           on the safe side for now. */
+        /* These colorspaces are supported, but they'll just have
+         * to be converted to I420 internally */
         return 0; /* VFCAP_CSP_SUPPORTED */
     }
     return 0;
@@ -288,14 +328,10 @@
 static int put_image(struct vf_instance_s *vf, mp_image_t *mpi)
 {
     h264_module_t *mod=(h264_module_t*)vf->priv;
-    int i_nal;
-    x264_nal_t *nal;
     int i;
-    int i_size = 0;
     
-    int csp=mod->pic.img.i_csp;
     memset(&mod->pic, 0, sizeof(x264_picture_t));
-    mod->pic.img.i_csp=csp;
+    mod->pic.img.i_csp=mod->param.i_csp;
     mod->pic.img.i_plane=3;
     for(i=0; i<4; i++) {
         mod->pic.img.plane[i] = mpi->planes[i];
@@ -303,9 +339,22 @@
     }
 
     mod->pic.i_type = X264_TYPE_AUTO;
-    if(x264_encoder_encode(mod->x264, &nal, &i_nal, &mod->pic) < 0) {
+
+    return encode_frame(vf, &mod->pic) >= 0;
+}
+
+static int encode_frame(struct vf_instance_s *vf, x264_picture_t *pic_in)
+{
+    h264_module_t *mod=(h264_module_t*)vf->priv;
+    x264_picture_t pic_out;
+    x264_nal_t *nal;
+    int i_nal;
+    int i_size = 0;
+    int i;
+
+    if(x264_encoder_encode(mod->x264, &nal, &i_nal, pic_in, &pic_out) < 0) {
         mp_msg(MSGT_MENCODER, MSGL_ERR, "x264_encoder_encode failed\n");
-        return 0;
+        return -1;
     }
     
     for(i=0; i < i_nal; i++) {
@@ -313,25 +362,25 @@
         i_size += x264_nal_encode(mod->mux->buffer + i_size, &i_data, 1, &nal[i]);
     }
     if(i_size>0) {
-        int keyframe = (mod->pic.i_type == X264_TYPE_IDR) ||
-                       (mod->pic.i_type == X264_TYPE_I && frame_ref == 1);
+        int keyframe = (pic_out.i_type == X264_TYPE_IDR) ||
+                       (pic_out.i_type == X264_TYPE_I
+                        && frame_ref == 1 && !bframe);
         muxer_write_chunk(mod->mux, i_size, keyframe?0x10:0);
     }
-    return 1;
+
+    return i_size;
 }
 
 static void uninit(struct vf_instance_s *vf)
 {
-    // FIXME: flush delayed frames
     h264_module_t *mod=(h264_module_t*)vf->priv;
     x264_encoder_close(mod->x264);
-    //x264_picture_clean(&mod->pic);
 }
 
 static int vf_open(vf_instance_t *vf, char *args) {
     h264_module_t *mod;
 
     vf->config = config;
     vf->control = control;
     vf->query_format = query_format;
     vf->put_image = put_image;
