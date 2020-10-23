--- third_party/blink/renderer/platform/graphics/video_frame_submitter.cc.orig	2020-09-08 19:14:11 UTC
+++ third_party/blink/renderer/platform/graphics/video_frame_submitter.cc
@@ -195,7 +195,7 @@ void VideoFrameSubmitter::OnBeginFrame(
     if (viz::FrameTokenGT(pair.key, *next_frame_token_))
       continue;
     auto& feedback = pair.value.presentation_feedback;
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO: On Linux failure flag is unreliable, and perfectly rendered frames
     // are reported as failures all the time.
     bool presentation_failure = false;
