--- third_party/blink/renderer/platform/graphics/video_frame_submitter.cc.orig	2024-10-27 06:40:35 UTC
+++ third_party/blink/renderer/platform/graphics/video_frame_submitter.cc
@@ -438,7 +438,7 @@ void VideoFrameSubmitter::OnBeginFrame(
     auto& details = timing_details.find(frame_token)->value;
     auto& feedback = details.presentation_feedback;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO: On Linux failure flag is unreliable, and perfectly rendered frames
     // are reported as failures all the time.
     bool presentation_failure = false;
