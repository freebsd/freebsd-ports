--- modules/codec/ffmpeg/video.c.orig	Fri May 13 13:30:36 2005
+++ modules/codec/ffmpeg/video.c	Fri May 13 13:32:42 2005
@@ -202,7 +202,7 @@
 
     p_pic = p_dec->pf_vout_buffer_new( p_dec );
 
-#ifdef LIBAVCODEC_PP
+#if defined(LIBAVCODEC_PP) && LIBAVCODEC_BUILD > 4750
     if( p_sys->p_pp && p_sys->b_pp && !p_sys->b_pp_init )
     {
         E_(InitPostproc)( p_dec, p_sys->p_pp, p_context->width,
@@ -301,7 +301,7 @@
         p_sys->b_direct_rendering = 1;
     }
 
-#ifdef LIBAVCODEC_PP
+#if defined(LIBAVCODEC_PP) && LIBAVCODE_BUILD > 4750
     p_sys->p_pp = NULL;
     p_sys->b_pp = p_sys->b_pp_async = p_sys->b_pp_init = VLC_FALSE;
     p_sys->p_pp = E_(OpenPostproc)( p_dec, &p_sys->b_pp_async );
@@ -719,7 +719,7 @@
 
     if( p_sys->p_ff_pic ) av_free( p_sys->p_ff_pic );
 
-#ifdef LIBAVCODEC_PP
+#if defined(LIBAVCODEC_PP) && LIBAVCODEC_BUILD > 4750
     E_(ClosePostproc)( p_dec, p_sys->p_pp );
 #endif
 
@@ -741,7 +741,7 @@
         uint8_t *p_dst, *p_src;
         int i_src_stride, i_dst_stride;
 
-#ifdef LIBAVCODEC_PP
+#if defined(LIBAVCODEC_PP) && LIBAVCODEC_BUILD > 4750
         if( p_sys->p_pp && p_sys->b_pp )
             E_(PostprocPict)( p_dec, p_sys->p_pp, p_pic, p_ff_pic );
         else
