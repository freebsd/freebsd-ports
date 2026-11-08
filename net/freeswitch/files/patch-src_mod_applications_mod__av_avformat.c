--- src/mod/applications/mod_av/avformat.c.orig	2026-10-03 00:00:00 UTC
+++ src/mod/applications/mod_av/avformat.c	2026-10-03 00:00:00 UTC
@@ -637,6 +637,7 @@
 		c->rc_initial_buffer_occupancy = buffer_bytes * 8;
 
 		if (codec_id == AV_CODEC_ID_H264) {
+#if (LIBAVCODEC_VERSION_MAJOR < 62) /* AVCodecContext.ticks_per_frame was removed in FFmpeg 8.0 */
 #if ((LIBAVFORMAT_VERSION_MAJOR == LIBAVFORMAT_6_V && LIBAVFORMAT_VERSION_MINOR >= LIBAVFORMAT_61_V) || LIBAVFORMAT_VERSION_MAJOR == LIBAVFORMAT_7_V)
 GCC_DIAG_OFF(deprecated-declarations)
 #endif
@@ -644,6 +645,7 @@
 #if ((LIBAVFORMAT_VERSION_MAJOR == LIBAVFORMAT_6_V && LIBAVFORMAT_VERSION_MINOR >= LIBAVFORMAT_61_V) || LIBAVFORMAT_VERSION_MAJOR == LIBAVFORMAT_7_V)
 GCC_DIAG_ON(deprecated-declarations)
 #endif
+#endif
 
 			c->flags|=AV_CODEC_FLAG_LOOP_FILTER;   // flags=+loop
 			c->me_cmp|= 1;  // cmp=+chroma, where CHROMA = 1
@@ -1431,7 +1433,7 @@
 		switch_goto_status(SWITCH_STATUS_FALSE, err);
 	}
 
-#if (LIBAVFORMAT_VERSION_MAJOR == LIBAVFORMAT_7_V)
+#if (LIBAVFORMAT_VERSION_MAJOR >= LIBAVFORMAT_7_V) /* AVInputFormat.read_seek/read_seek2 were removed in FFmpeg 8.0 */
 	handle->seekable = !(context->fc->iformat->flags & AVFMT_NOTIMESTAMPS);
 #else
 	handle->seekable = context->fc->iformat->read_seek2 ? 1 : (context->fc->iformat->read_seek ? 1 : 0);
@@ -3124,6 +3126,7 @@
 	MediaStream *mst = &context->video_st;
 	AVStream *st = mst->st;
 	int ticks = 0;
+	int ticks_per_frame = -1;
 	int64_t max_delta = 1 * AV_TIME_BASE; // 1 second
 	switch_status_t status = SWITCH_STATUS_SUCCESS;
 	double fl_to = 0.02;
@@ -3243,13 +3246,18 @@
 #if ((LIBAVFORMAT_VERSION_MAJOR == LIBAVFORMAT_6_V && LIBAVFORMAT_VERSION_MINOR >= LIBAVFORMAT_61_V) || LIBAVFORMAT_VERSION_MAJOR == LIBAVFORMAT_7_V)
 GCC_DIAG_OFF(deprecated-declarations)
 #endif
+#if (LIBAVCODEC_VERSION_MAJOR >= 62) /* AVCodecContext.ticks_per_frame was removed in FFmpeg 8.0 */
+		ticks = cp ? cp->repeat_pict + 1 : 1;
+#else
 		ticks = cp ? cp->repeat_pict + 1 : c->ticks_per_frame;
+		ticks_per_frame = c->ticks_per_frame;
+#endif
 		// mst->next_pts += ((int64_t)AV_TIME_BASE * st->codec->time_base.num * ticks) / st->codec->time_base.den;
 	}
 
 	if (!context->video_start_time) {
 		switch_log_printf(SWITCH_CHANNEL_LOG, SWITCH_LOG_DEBUG1, "start: %" SWITCH_INT64_T_FMT " ticks: %d ticks_per_frame: %d st num:%d st den:%d codec num:%d codec den:%d start: %" SWITCH_TIME_T_FMT ", duration:%" SWITCH_INT64_T_FMT " nb_frames:%" SWITCH_INT64_T_FMT " q2d:%f\n",
-			context->video_start_time, ticks, c ? c->ticks_per_frame : -1, st->time_base.num, st->time_base.den, c ? c->time_base.num : -1, c ? c->time_base.den : -1,
+			context->video_start_time, ticks, ticks_per_frame, st->time_base.num, st->time_base.den, c ? c->time_base.num : -1, c ? c->time_base.den : -1,
 			st->start_time, st->duration == AV_NOPTS_VALUE ? context->fc->duration / AV_TIME_BASE * 1000 : st->duration, st->nb_frames, av_q2d(st->time_base));
 	}
 #if ((LIBAVFORMAT_VERSION_MAJOR == LIBAVFORMAT_6_V && LIBAVFORMAT_VERSION_MINOR >= LIBAVFORMAT_61_V) || LIBAVFORMAT_VERSION_MAJOR == LIBAVFORMAT_7_V)
