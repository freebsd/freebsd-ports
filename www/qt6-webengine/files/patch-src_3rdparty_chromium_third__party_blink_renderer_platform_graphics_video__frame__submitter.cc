--- src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/video_frame_submitter.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/video_frame_submitter.cc
@@ -358,7 +358,7 @@ void VideoFrameSubmitter::OnBeginFrame(
       continue;
     auto& feedback =
         timing_details.find(frame_token)->value.presentation_feedback;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO: On Linux failure flag is unreliable, and perfectly rendered frames
     // are reported as failures all the time.
     bool presentation_failure = false;
