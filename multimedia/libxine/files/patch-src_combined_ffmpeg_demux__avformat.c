--- src/combined/ffmpeg/demux_avformat.c.orig	2022-09-08 21:43:29 UTC
+++ src/combined/ffmpeg/demux_avformat.c
@@ -1,5 +1,5 @@
 /*
- * Copyright (C) 2013-2022 the xine project
+ * Copyright (C) 2013-2023 the xine project
  * Copyright (C) 2013-2020 Petri Hintukainen <phintuka@users.sourceforge.net>
  *
  * This file is part of xine, a free video player.
@@ -423,8 +423,13 @@ static int find_avformat_streams(avformat_demux_plugin
     }
 
 #ifdef XFF_CODECPAR
+#  if XFF_AUDIO_CHANNEL_LAYOUT < 2
     if (st->codecpar && st->codecpar->codec_type == AVMEDIA_TYPE_AUDIO &&
         st->codecpar->sample_rate != 0 && st->codecpar->channels != 0)
+#  else
+    if (st->codecpar && st->codecpar->codec_type == AVMEDIA_TYPE_AUDIO &&
+        st->codecpar->sample_rate != 0 && st->codecpar->ch_layout.nb_channels != 0)
+#  endif
 #else
     if (st->codec && st->codec->codec_type == AVMEDIA_TYPE_AUDIO &&
         st->codec->sample_rate != 0 && st->codec->channels != 0)
@@ -501,7 +506,11 @@ static void send_headers_audio(avformat_demux_plugin_t
   buf->size = extradata_size + sizeof(xine_waveformatex);
   buf->decoder_info[1] = ctx->sample_rate;
   buf->decoder_info[2] = ctx->bits_per_coded_sample;
+#if XFF_AUDIO_CHANNEL_LAYOUT < 2
   buf->decoder_info[3] = ctx->channels;
+#else
+  buf->decoder_info[3] = ctx->ch_layout.nb_channels;
+#endif
   buf->decoder_flags = BUF_FLAG_HEADER | BUF_FLAG_STDHEADER | BUF_FLAG_FRAME_END;
 
   this->stream->audio_fifo->put (this->stream->audio_fifo, buf);
