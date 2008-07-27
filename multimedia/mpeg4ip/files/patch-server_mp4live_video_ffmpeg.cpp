--- server/mp4live/video_ffmpeg.cpp.orig	2008-07-27 18:33:54.140404708 -0500
+++ server/mp4live/video_ffmpeg.cpp	2008-07-27 18:34:54.699683611 -0500
@@ -121,9 +121,6 @@
   m_avctx->bit_rate = 
     Profile()->GetIntegerValue(CFG_VIDEO_BIT_RATE) * 1000;
 #ifndef HAVE_AVCODECCONTEXT_TIME_BASE
-  m_avctx->frame_rate = (int)(Profile()->GetFloatValue(CFG_VIDEO_FRAME_RATE) + 0.5);
-  m_avctx->frame_rate_base = 1;
-#else
   m_avctx->time_base = (AVRational){1, (int)(Profile()->GetFloatValue(CFG_VIDEO_FRAME_RATE) + .5)};
   m_avctx->pix_fmt = PIX_FMT_YUV420P;
   m_avctx->me_method = ME_EPZS;
@@ -131,9 +128,9 @@
   if (Profile()->GetIntegerValue(CFG_VIDEO_MPEG4_PAR_WIDTH) > 0 &&
       Profile()->GetIntegerValue(CFG_VIDEO_MPEG4_PAR_HEIGHT) > 0) {
 #ifndef HAVE_AVRATIONAL
-    float asp = (float)Profile()->GetIntegerValue(CFG_VIDEO_MPEG4_PAR_WIDTH);
-    asp /= (float)Profile()->GetIntegerValue(CFG_VIDEO_MPEG4_PAR_HEIGHT);
-    m_avctx->aspect_ratio = asp;
+     AVRational asp =      {Profile()->GetIntegerValue(CFG_VIDEO_MPEG4_PAR_WIDTH),
+       Profile()->GetIntegerValue(CFG_VIDEO_MPEG4_PAR_HEIGHT)};   
+       m_avctx->sample_aspect_ratio = asp;
 #else
     AVRational asp = 
       {Profile()->GetIntegerValue(CFG_VIDEO_MPEG4_PAR_WIDTH),
