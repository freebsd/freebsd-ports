--- third_party/blink/renderer/platform/graphics/video_frame_submitter.cc.orig	2021-12-14 11:45:12 UTC
+++ third_party/blink/renderer/platform/graphics/video_frame_submitter.cc
@@ -321,7 +321,7 @@ void VideoFrameSubmitter::OnBeginFrame(
       continue;
     auto& feedback =
         timing_details.find(frame_token)->value.presentation_feedback;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // TODO: On Linux failure flag is unreliable, and perfectly rendered frames
     // are reported as failures all the time.
     bool presentation_failure = false;
