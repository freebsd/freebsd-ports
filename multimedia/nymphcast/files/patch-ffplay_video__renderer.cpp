--- ffplay/video_renderer.cpp.orig	2022-02-05 21:45:21 UTC
+++ ffplay/video_renderer.cpp
@@ -204,7 +204,7 @@ display:
 			//FileMetaInfo::position = master_clock;	// Copy to FleMetaInfo structure for the current file.
 			FileMetaInfo::setPosition(master_clock);
             av_log(NULL, AV_LOG_INFO,
-                   "%7.2f %s:%7.3f fd=%4d aq=%5dKB vq=%5dKB sq=%5dB f=%"PRId64"/%"PRId64"   \r",
+                   "%7.2f %s:%7.3f fd=%4d aq=%5dKB vq=%5dKB sq=%5dB f=%" PRId64 "/%" PRId64 "   \r",
                    master_clock,
                    (is->audio_st && is->video_st) ? "A-V" : (is->video_st ? "M-V" : (is->audio_st ? "M-A" : "   ")),
                    av_diff,
