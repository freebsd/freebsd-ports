--- src/mediatrc_ffmpeg.cpp.orig	2011-11-01 15:57:37.937699918 +0100
+++ src/mediatrc_ffmpeg.cpp	2011-11-01 15:56:04.978979342 +0100
@@ -1360,6 +1360,7 @@
 				ost->enc = avcodec_find_encoder(ost->st->codec->codec_id);
 			switch (codec->codec_type) {
 			case AVMEDIA_TYPE_AUDIO:
+				{
 				ost->fifo= av_fifo_alloc(1024);
 				if(!ost->fifo)
 					goto fail;
@@ -1382,8 +1383,10 @@
                 ost->resample_sample_fmt  = icodec->sample_fmt;
                 ost->resample_sample_rate = icodec->sample_rate;
                 ost->resample_channels    = icodec->channels;
+			}
 				break;
 			case AVMEDIA_TYPE_VIDEO:
+				{
 				if (codec->pix_fmt == PIX_FMT_NONE)
 					codec->pix_fmt = icodec->pix_fmt;
 				choose_pixel_fmt(ost->st, ost->enc);
@@ -1423,6 +1426,7 @@
                     wxLogError(wxT("Error opening filters!"));
                     return false;
                 }
+				}
 				break;
 			case AVMEDIA_TYPE_SUBTITLE:
 				ost->encoding_needed = 1;
