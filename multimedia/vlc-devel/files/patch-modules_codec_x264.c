--- modules/codec/x264.c.orig	Thu Nov 11 13:50:16 2004
+++ modules/codec/x264.c	Thu Apr 21 08:45:37 2005
@@ -2,7 +2,7 @@
  * x264.c: h264 video encoder
  *****************************************************************************
  * Copyright (C) 2004 VideoLAN
- * $Id: x264.c 9280 2004-11-11 12:31:27Z zorglub $
+ * $Id: x264.c 10206 2005-03-08 13:15:56Z gbazin $
  *
  * Authors: Laurent Aimar <fenrir@via.ecp.fr>
  *
@@ -62,17 +62,19 @@
 #define ANALYSE_TEXT N_("Analyse mode")
 #define ANALYSE_LONGTEXT N_( "This selects the analysing mode.")
 
-#define KEYINT_TEXT N_("Sets maximum interval between I frames")
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
@@ -125,8 +129,8 @@
     add_integer( SOUT_CFG_PREFIX "keyint", 250, NULL, KEYINT_TEXT,
                  KEYINT_LONGTEXT, VLC_FALSE );
 
-    add_integer( SOUT_CFG_PREFIX "idrint", 2, NULL, IDRINT_TEXT,
-                 IDRINT_LONGTEXT, VLC_FALSE );
+    add_integer( SOUT_CFG_PREFIX "keyint-min", 0, NULL, KEYINT_MIN_TEXT,
+                 KEYINT_MIN_LONGTEXT, VLC_FALSE );
 
     add_integer( SOUT_CFG_PREFIX "bframes", 0, NULL, BFRAMES_TEXT,
                  BFRAMES_LONGTEXT, VLC_FALSE );
@@ -147,7 +151,7 @@
  *****************************************************************************/
 static const char *ppsz_sout_options[] = {
     "qp", "qp-min", "qp-max", "cabac", "loopfilter", "analyse",
-    "keyint", "idrint", "bframes", "frameref", "scenecut", NULL
+    "keyint", "keyint-min", "bframes", "frameref", "scenecut", NULL
 };
 
 static block_t *Encode( encoder_t *, picture_t * );
@@ -236,10 +240,19 @@
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
@@ -273,6 +286,7 @@
         p_sys->param.analyse.inter =
             X264_ANALYSE_I4x4 | X264_ANALYSE_PSUB16x16 | X264_ANALYSE_PSUB8x8;
     }
+    if( val.psz_string ) free( val.psz_string );
 
     if( p_enc->fmt_in.video.i_aspect > 0 )
     {
@@ -347,12 +361,10 @@
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
@@ -364,7 +376,11 @@
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
