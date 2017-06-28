--- media/filters/ffmpeg_demuxer.cc.orig	2017-06-05 19:03:08 UTC
+++ media/filters/ffmpeg_demuxer.cc
@@ -1223,6 +1223,7 @@ void FFmpegDemuxer::OnFindStreamInfoDone(const Pipelin
   // If no estimate is found, the stream entry will be kInfiniteDuration.
   std::vector<base::TimeDelta> start_time_estimates(format_context->nb_streams,
                                                     kInfiniteDuration);
+#if !defined(USE_SYSTEM_FFMPEG)
   const AVFormatInternal* internal = format_context->internal;
   if (internal && internal->packet_buffer &&
       format_context->start_time != static_cast<int64_t>(AV_NOPTS_VALUE)) {
@@ -1246,6 +1247,7 @@ void FFmpegDemuxer::OnFindStreamInfoDone(const Pipelin
       packet_buffer = packet_buffer->next;
     }
   }
+#endif // !defined(USE_SYSTEM_FFMPEG)
 
   std::unique_ptr<MediaTracks> media_tracks(new MediaTracks());
 
