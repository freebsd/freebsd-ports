--- src/vp/gstplayer.cc.orig	2014-02-12 22:02:59 UTC
+++ src/vp/gstplayer.cc
@@ -261,7 +261,7 @@ bool GstPlayer::seek(long start, long en
 	gint64 gend = end * Gst::MILLI_SECOND;
 
 	se_debug_message(SE_DEBUG_VIDEO_PLAYER,
-			"pipeline->seek(%" GST_TIME_FORMAT", %"GST_TIME_FORMAT")", 
+			"pipeline->seek(%" GST_TIME_FORMAT", %" GST_TIME_FORMAT")", 
 			GST_TIME_ARGS(gstart), GST_TIME_ARGS(gend));
 
 	bool ret = m_pipeline->seek(
