--- modules/codec/x264.c.orig	Thu Nov 11 13:50:16 2004
+++ modules/codec/x264.c	Sat May 21 16:14:56 2005
@@ -2,7 +2,7 @@
  * x264.c: h264 video encoder
  *****************************************************************************
  * Copyright (C) 2004 VideoLAN
- * $Id: x264.c 9280 2004-11-11 12:31:27Z zorglub $
+ * $Id: x264.c 10990 2005-05-13 11:13:05Z gbazin $
  *
  * Authors: Laurent Aimar <fenrir@via.ecp.fr>
  *
@@ -62,22 +62,43 @@
 #define ANALYSE_TEXT N_("Analyse mode")
 #define ANALYSE_LONGTEXT N_( "This selects the analysing mode.")
 
-#define KEYINT_TEXT N_("Sets maximum interval between I frames")
+#define TOLERANCE_TEXT N_("Bitrate tolerance")
+#define TOLERANCE_LONGTEXT N_( "Sets the allowed variance in average " \
+    "bitrate.")
+
+#define VBV_MAXRATE_TEXT N_("Maximum local bitrate")
+#define VBV_MAXRATE_LONGTEXT N_( "Sets a maximum local bitrate in kbits/s.")
+
+#define VBV_BUFSIZE_TEXT N_("Averaging period for the maximum local bitrate")
+#define VBV_BUFSIZE_LONGTEXT N_( "Sets an averaging preiod for the maximum " \
+    "local bitrate, in kbits/s.")
+
+#define VBV_INIT_TEXT N_("Initial buffer occupancy")
+#define VBV_INIT_LONGTEXT N_( "Sets the initial buffer occupancy as a " \
+    "fraction of the buffer size.")
+
+#define KEYINT_TEXT N_("Sets maximum interval between IDR-frames")
 #define KEYINT_LONGTEXT N_( "Larger values save bits, thus improve quality "\
     "for a given bitrate, at the cost of seeking precision." )
 
-#define IDRINT_TEXT N_("IDR frames")
-#define IDRINT_LONGTEXT N_("In H.264, I-Frames do not necessarily bound a " \
-    "closed GOP because it is allowable for a P-frame to be predicted from " \
+#define KEYINT_MIN_TEXT N_("Sets minimum interval between IDR-frames")
+#define KEYINT_MIN_LONGTEXT N_("In H.264, I-Frames do not necessarily bound " \
+    "a closed GOP because it is allowable for a P-frame to be predicted from "\
     "more frames than just the one frame before it (also see frameref). " \
     "Therefore, I-frames are not necessarily seekable. " \
     "IDR-Frames restrict subsequent P-frames from referring to any frame " \
-    "prior to the IDR-Frame." )
+    "prior to the IDR-Frame. \n" \
+    "If scenecuts appear within this interval, they are still encoded as " \
+    "I-frames, but do not start a new GOP. Default value is keyint * 0.4." )
 
 #define BFRAMES_TEXT N_("B frames")
 #define BFRAMES_LONGTEXT N_( "Number of consecutive B-Frames between I and " \
     "P-frames." )
 
+#define BPYRAMID_TEXT N_("B pyramid")
+#define BPYRAMID_LONGTEXT N_( "Allows B-frames to be used as references for " \
+    "predicting other frames." )
+
 #define FRAMEREF_TEXT N_("Number of previous frames used as predictors.")
 #define FRAMEREF_LONGTEXT N_( "This is effective in Anime, but seems to " \
     "make little difference in live-action source material. Some decoders " \
@@ -92,6 +113,11 @@
     "-1 disables scene-cut detection, so I-frames are be inserted only every "\
     "other keyint frames, which probably leads to ugly encoding artifacts." )
 
+#define SUBPEL_TEXT N_("Sub-pixel refinement quality.")
+#define SUBPEL_LONGTEXT N_( "This parameter controls quality versus speed " \
+    "tradeoffs involved in the motion estimation decision process " \
+    "(lower = quicker and higher = better quality)." )
+
 static char *enc_analyse_list[] =
   { "", "all", "normal", "fast", "none" };
 static char *enc_analyse_list_text[] =
@@ -122,16 +150,33 @@
                 ANALYSE_LONGTEXT, VLC_FALSE );
         change_string_list( enc_analyse_list, enc_analyse_list_text, 0 );
 
+    add_float( SOUT_CFG_PREFIX "tolerance", 1.0, NULL, TOLERANCE_TEXT,
+               TOLERANCE_LONGTEXT, VLC_FALSE );
+        change_float_range( 0, 100 );
+
+    add_integer( SOUT_CFG_PREFIX "vbv-maxrate", 0, NULL, VBV_MAXRATE_TEXT,
+                 VBV_MAXRATE_LONGTEXT, VLC_FALSE );
+
+    add_integer( SOUT_CFG_PREFIX "vbv-bufsize", 0, NULL, VBV_BUFSIZE_TEXT,
+                 VBV_BUFSIZE_LONGTEXT, VLC_FALSE );
+
+    add_float( SOUT_CFG_PREFIX "vbv-init", 0.9, NULL, VBV_INIT_TEXT,
+               VBV_INIT_LONGTEXT, VLC_FALSE );
+        change_float_range( 0, 1 );
+
     add_integer( SOUT_CFG_PREFIX "keyint", 250, NULL, KEYINT_TEXT,
                  KEYINT_LONGTEXT, VLC_FALSE );
 
-    add_integer( SOUT_CFG_PREFIX "idrint", 2, NULL, IDRINT_TEXT,
-                 IDRINT_LONGTEXT, VLC_FALSE );
+    add_integer( SOUT_CFG_PREFIX "keyint-min", 0, NULL, KEYINT_MIN_TEXT,
+                 KEYINT_MIN_LONGTEXT, VLC_FALSE );
 
     add_integer( SOUT_CFG_PREFIX "bframes", 0, NULL, BFRAMES_TEXT,
                  BFRAMES_LONGTEXT, VLC_FALSE );
         change_integer_range( 0, 16 );
 
+    add_bool( SOUT_CFG_PREFIX "bpyramid", 0, NULL, BPYRAMID_TEXT,
+              BPYRAMID_LONGTEXT, VLC_FALSE );
+
     add_integer( SOUT_CFG_PREFIX "frameref", 1, NULL, FRAMEREF_TEXT,
                  FRAMEREF_LONGTEXT, VLC_FALSE );
         change_integer_range( 1, 15 );
@@ -140,6 +185,10 @@
                  SCENE_LONGTEXT, VLC_FALSE );
         change_integer_range( -1, 100 );
 
+    add_integer( SOUT_CFG_PREFIX "subpel", 5, NULL, SUBPEL_TEXT,
+                 SUBPEL_LONGTEXT, VLC_FALSE );
+        change_integer_range( 1, 5 );
+
 vlc_module_end();
 
 /*****************************************************************************
@@ -147,7 +196,8 @@
  *****************************************************************************/
 static const char *ppsz_sout_options[] = {
     "qp", "qp-min", "qp-max", "cabac", "loopfilter", "analyse",
-    "keyint", "idrint", "bframes", "frameref", "scenecut", NULL
+    "keyint", "keyint-min", "bframes", "bpyramid", "frameref", "scenecut",
+    "subpel", "tolerance", "vbv-maxrate", "vbv-bufsize", "vbv-init", NULL
 };
 
 static block_t *Encode( encoder_t *, picture_t * );
@@ -180,10 +230,19 @@
     if( p_enc->fmt_in.video.i_width % 16 != 0 ||
         p_enc->fmt_in.video.i_height % 16!= 0 )
     {
-        msg_Warn( p_enc, "invalid size %ix%i",
-                  p_enc->fmt_in.video.i_width,
-                  p_enc->fmt_in.video.i_height );
-        return VLC_EGENERIC;
+        msg_Warn( p_enc, "size is not a multiple of 16 (%ix%i)",
+                  p_enc->fmt_in.video.i_width, p_enc->fmt_in.video.i_height );
+
+        if( p_enc->fmt_in.video.i_width < 16 ||
+            p_enc->fmt_in.video.i_height < 16 )
+        {
+            msg_Err( p_enc, "video is too small to be cropped" );
+            return VLC_EGENERIC;
+        }
+
+        msg_Warn( p_enc, "cropping video to %ix%i",
+                  p_enc->fmt_in.video.i_width >> 4 << 4,
+                  p_enc->fmt_in.video.i_height >> 4 << 4 );
     }
 
     sout_CfgParse( p_enc, SOUT_CFG_PREFIX, ppsz_sout_options, p_enc->p_cfg );
@@ -196,8 +255,8 @@
     p_enc->p_sys = p_sys = malloc( sizeof( encoder_sys_t ) );
 
     x264_param_default( &p_sys->param );
-    p_sys->param.i_width  = p_enc->fmt_in.video.i_width;
-    p_sys->param.i_height = p_enc->fmt_in.video.i_height;
+    p_sys->param.i_width  = p_enc->fmt_in.video.i_width >> 4 << 4;
+    p_sys->param.i_height = p_enc->fmt_in.video.i_height >> 4 << 4;
 
     var_Get( p_enc, SOUT_CFG_PREFIX "qp-min", &val );
     if( val.i_int >= 1 && val.i_int <= 51 ) i_qmin = val.i_int;
@@ -224,9 +283,26 @@
 #if X264_BUILD >= 0x000a
         p_sys->param.rc.b_cbr = 1;
         p_sys->param.rc.i_bitrate = p_enc->fmt_out.i_bitrate / 1000;
+
+#if X264_BUILD >= 24
+        var_Get( p_enc, SOUT_CFG_PREFIX "tolerance", &val );
+        p_sys->param.rc.f_rate_tolerance = val.f_float;
+
+        var_Get( p_enc, SOUT_CFG_PREFIX "vbv-maxrate", &val );
+        p_sys->param.rc.i_vbv_max_bitrate = val.i_int;
+
+        var_Get( p_enc, SOUT_CFG_PREFIX "vbv-bufsize", &val );
+        p_sys->param.rc.i_vbv_buffer_size = val.i_int;
+        if( !val.i_int )
+            p_sys->param.rc.i_vbv_buffer_size = p_sys->param.rc.i_bitrate;
+
+        var_Get( p_enc, SOUT_CFG_PREFIX "vbv-init", &val );
+        p_sys->param.rc.f_vbv_buffer_init = val.f_float;
+#else
         p_sys->param.rc.i_rc_buffer_size = p_sys->param.rc.i_bitrate;
         p_sys->param.rc.i_rc_init_buffer = p_sys->param.rc.i_bitrate / 4;
 #endif
+#endif
     }
 
     var_Get( p_enc, SOUT_CFG_PREFIX "cabac", &val );
@@ -236,14 +312,28 @@
     p_sys->param.b_deblocking_filter = val.b_bool;
 
     var_Get( p_enc, SOUT_CFG_PREFIX "keyint", &val );
+#if X264_BUILD >= 0x000e
+    if( val.i_int > 0 ) p_sys->param.i_keyint_max = val.i_int;
+    if( val.i_int > 0 ) p_sys->param.i_keyint_min = val.i_int * 0.4;
+#else
     if( val.i_int > 0 ) p_sys->param.i_iframe = val.i_int;
+#endif
 
-    var_Get( p_enc, SOUT_CFG_PREFIX "idrint", &val );
+    var_Get( p_enc, SOUT_CFG_PREFIX "keyint-min", &val );
+#if X264_BUILD >= 0x000e
+    if( val.i_int > 0 ) p_sys->param.i_keyint_min = val.i_int;
+#else
     if( val.i_int > 0 ) p_sys->param.i_idrframe = val.i_int;
+#endif
 
     var_Get( p_enc, SOUT_CFG_PREFIX "bframes", &val );
     if( val.i_int >= 0 && val.i_int <= 16 ) p_sys->param.i_bframe = val.i_int;
 
+#if X264_BUILD >= 22
+    var_Get( p_enc, SOUT_CFG_PREFIX "bpyramid", &val );
+    p_sys->param.b_bframe_pyramid = val.b_bool;
+#endif
+
     var_Get( p_enc, SOUT_CFG_PREFIX "frameref", &val );
     if( val.i_int > 0 && val.i_int <= 15 )
         p_sys->param.i_frame_reference = val.i_int;
@@ -254,6 +344,12 @@
         p_sys->param.i_scenecut_threshold = val.i_int;
 #endif
 
+#if X264_BUILD >= 22
+    var_Get( p_enc, SOUT_CFG_PREFIX "subpel", &val );
+    if( val.i_int >= 1 && val.i_int <= 5 )
+        p_sys->param.analyse.i_subpel_refine = val.i_int;
+#endif
+
     var_Get( p_enc, SOUT_CFG_PREFIX "analyse", &val );
     if( !strcmp( val.psz_string, "none" ) )
     {
@@ -270,9 +366,14 @@
     }
     else if( !strcmp( val.psz_string, "all" ) )
     {
+#ifndef X264_ANALYSE_BSUB16x16
+#   define X264_ANALYSE_BSUB16x16 0
+#endif
         p_sys->param.analyse.inter =
-            X264_ANALYSE_I4x4 | X264_ANALYSE_PSUB16x16 | X264_ANALYSE_PSUB8x8;
+            X264_ANALYSE_I4x4 | X264_ANALYSE_PSUB16x16 | X264_ANALYSE_PSUB8x8 |
+            X264_ANALYSE_BSUB16x16;
     }
+    if( val.psz_string ) free( val.psz_string );
 
     if( p_enc->fmt_in.video.i_aspect > 0 )
     {
@@ -347,12 +448,10 @@
 static block_t *Encode( encoder_t *p_enc, picture_t *p_pict )
 {
     encoder_sys_t *p_sys = p_enc->p_sys;
-    x264_picture_t  pic;
-    int        i_nal;
+    x264_picture_t pic;
     x264_nal_t *nal;
     block_t *p_block;
-    int i_out;
-    int i;
+    int i_nal, i_out, i;
 
     /* init pic */
     memset( &pic, 0, sizeof( x264_picture_t ) );
@@ -364,7 +463,11 @@
         pic.img.i_stride[i] = p_pict->p[i].i_pitch;
     }
 
+#if X264_BUILD >= 0x0013
+    x264_encoder_encode( p_sys->h, &nal, &i_nal, &pic, &pic );
+#else
     x264_encoder_encode( p_sys->h, &nal, &i_nal, &pic );
+#endif
     for( i = 0, i_out = 0; i < i_nal; i++ )
     {
         int i_size = p_sys->i_buffer - i_out;
