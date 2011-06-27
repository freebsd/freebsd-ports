--- src/mediatrc_ffmpeg.cpp.orig	2011-06-27 23:31:11.388593646 +0200
+++ src/mediatrc_ffmpeg.cpp	2011-06-28 00:27:55.361966692 +0200
@@ -2567,7 +2567,7 @@
 			} else
 				big_picture.quality = (int) ost->st->quality;
 			if (!me_threshold)
-				big_picture.pict_type = 0;
+				big_picture.pict_type = AV_PICTURE_TYPE_NONE;
 //			big_picture.pts = AV_NOPTS_VALUE;
 			big_picture.pts= ost->sync_opts;
 //			big_picture.pts= av_rescale(ost->sync_opts, AV_TIME_BASE*(int64_t)enc->time_base.num, enc->time_base.den);
