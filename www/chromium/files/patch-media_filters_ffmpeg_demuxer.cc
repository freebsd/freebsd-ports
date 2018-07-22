--- media/filters/ffmpeg_demuxer.cc.orig	2018-06-13 00:10:20.000000000 +0200
+++ media/filters/ffmpeg_demuxer.cc	2018-07-20 16:10:50.322176000 +0200
@@ -85,29 +85,26 @@
       frames * base::Time::kMicrosecondsPerSecond / sample_rate);
 }
 
-static base::TimeDelta ExtractStartTime(AVStream* stream,
-                                        base::TimeDelta start_time_estimate) {
-  DCHECK(start_time_estimate != kNoTimestamp);
-  if (stream->start_time == static_cast<int64_t>(AV_NOPTS_VALUE)) {
-    return start_time_estimate == kInfiniteDuration ? base::TimeDelta()
-                                                    : start_time_estimate;
-  }
+static base::TimeDelta ExtractStartTime(AVStream* stream) {
+  // The default start time is zero.
+  base::TimeDelta start_time;
 
-  // First try the lower of the estimate and the |start_time| value.
-  base::TimeDelta start_time =
-      std::min(ConvertFromTimeBase(stream->time_base, stream->start_time),
-               start_time_estimate);
+  // First try to use the |start_time| value as is.
+  if (stream->start_time != kNoFFmpegTimestamp)
+    start_time = ConvertFromTimeBase(stream->time_base, stream->start_time);
 
-  // Next see if the first buffered pts value is usable.
-  if (stream->pts_buffer[0] != static_cast<int64_t>(AV_NOPTS_VALUE)) {
-    const base::TimeDelta buffered_pts =
-        ConvertFromTimeBase(stream->time_base, stream->pts_buffer[0]);
-    if (buffered_pts < start_time)
-      start_time = buffered_pts;
+  // Next try to use the first DTS value, for codecs where we know PTS == DTS
+  // (exclude all H26x codecs). The start time must be returned in PTS.
+  if (stream->first_dts != kNoFFmpegTimestamp &&
+      stream->codecpar->codec_id != AV_CODEC_ID_HEVC &&
+      stream->codecpar->codec_id != AV_CODEC_ID_H264 &&
+      stream->codecpar->codec_id != AV_CODEC_ID_MPEG4) {
+    const base::TimeDelta first_pts =
+        ConvertFromTimeBase(stream->time_base, stream->first_dts);
+    if (first_pts < start_time)
+      start_time = first_pts;
   }
 
-  // NOTE: Do not use AVStream->first_dts since |start_time| should be a
-  // presentation timestamp.
   return start_time;
 }
 
@@ -514,7 +511,7 @@
     buffer->set_duration(kNoTimestamp);
   }
 
-  // Note: If pts is AV_NOPTS_VALUE, stream_timestamp will be kNoTimestamp.
+  // Note: If pts is kNoFFmpegTimestamp, stream_timestamp will be kNoTimestamp.
   const base::TimeDelta stream_timestamp =
       ConvertStreamTimestamp(stream_->time_base, packet->pts);
 
@@ -557,8 +554,8 @@
   // code paths below; otherwise they should be treated as a parse error.
   if ((!fixup_chained_ogg_ || last_packet_timestamp_ == kNoTimestamp) &&
       buffer->timestamp() < base::TimeDelta()) {
-    MEDIA_LOG(DEBUG, media_log_)
-        << "FFmpegDemuxer: unfixable negative timestamp";
+    MEDIA_LOG(ERROR, media_log_)
+        << "FFmpegDemuxer: unfixable negative timestamp.";
     demuxer_->NotifyDemuxerError(DEMUXER_ERROR_COULD_NOT_PARSE);
     return;
   }
@@ -871,7 +868,7 @@
 base::TimeDelta FFmpegDemuxerStream::ConvertStreamTimestamp(
     const AVRational& time_base,
     int64_t timestamp) {
-  if (timestamp == static_cast<int64_t>(AV_NOPTS_VALUE))
+  if (timestamp == kNoFFmpegTimestamp)
     return kNoTimestamp;
 
   return ConvertFromTimeBase(time_base, timestamp);
@@ -1271,42 +1268,6 @@
   AVFormatContext* format_context = glue_->format_context();
   streams_.resize(format_context->nb_streams);
 
-  // Estimate the start time for each stream by looking through the packets
-  // buffered during avformat_find_stream_info().  These values will be
-  // considered later when determining the actual stream start time.
-  //
-  // These packets haven't been completely processed yet, so only look through
-  // these values if the AVFormatContext has a valid start time.
-  //
-  // If no estimate is found, the stream entry will be kInfiniteDuration.
-  std::vector<base::TimeDelta> start_time_estimates(format_context->nb_streams,
-                                                    kInfiniteDuration);
-#if !BUILDFLAG(USE_SYSTEM_FFMPEG)
-  const AVFormatInternal* internal = format_context->internal;
-  if (internal && internal->packet_buffer &&
-      format_context->start_time != static_cast<int64_t>(AV_NOPTS_VALUE)) {
-    struct AVPacketList* packet_buffer = internal->packet_buffer;
-    while (packet_buffer != internal->packet_buffer_end) {
-      DCHECK_LT(static_cast<size_t>(packet_buffer->pkt.stream_index),
-                start_time_estimates.size());
-      const AVStream* stream =
-          format_context->streams[packet_buffer->pkt.stream_index];
-      if (packet_buffer->pkt.pts != static_cast<int64_t>(AV_NOPTS_VALUE)) {
-        const base::TimeDelta packet_pts =
-            ConvertFromTimeBase(stream->time_base, packet_buffer->pkt.pts);
-        // We ignore kNoTimestamp here since -int64_t::min() is possible; see
-        // https://crbug.com/700501. Technically this is a valid value, but in
-        // practice shouldn't occur, so just ignore it when estimating.
-        if (packet_pts != kNoTimestamp && packet_pts != kInfiniteDuration &&
-            packet_pts < start_time_estimates[stream->index]) {
-          start_time_estimates[stream->index] = packet_pts;
-        }
-      }
-      packet_buffer = packet_buffer->next;
-    }
-  }
-#endif  // !BUILDFLAG(USE_SYSTEM_FFMPEG)
-
   std::unique_ptr<MediaTracks> media_tracks(new MediaTracks());
 
   DCHECK(track_id_to_demux_stream_map_.empty());
@@ -1455,8 +1416,7 @@
 
     max_duration = std::max(max_duration, streams_[i]->duration());
 
-    base::TimeDelta start_time =
-        ExtractStartTime(stream, start_time_estimates[i]);
+    base::TimeDelta start_time = ExtractStartTime(stream);
 
     // Note: This value is used for seeking, so we must take the true value and
     // not the one possibly clamped to zero below.
@@ -1494,7 +1454,7 @@
   if (text_enabled_)
     AddTextStreams();
 
-  if (format_context->duration != static_cast<int64_t>(AV_NOPTS_VALUE)) {
+  if (format_context->duration != kNoFFmpegTimestamp) {
     // If there is a duration value in the container use that to find the
     // maximum between it and the duration from A/V streams.
     const AVRational av_time_base = {1, AV_TIME_BASE};
