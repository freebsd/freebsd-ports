--- libs/libmythtv/videoout_vdpau.cpp.orig	2015-06-16 16:03:30 UTC
+++ libs/libmythtv/videoout_vdpau.cpp
@@ -442,7 +442,7 @@ void VideoOutputVDPAU::PrepareFrame(VideoFrame *frame,
     if (frame)
     {
         // FIXME for 0.23. This should be triggered from AFD by a seek
-        if ((abs(frame->frameNumber - framesPlayed) > 8))
+        if ((labs(frame->frameNumber - framesPlayed) > 8))
             ClearReferenceFrames();
         new_frame = (framesPlayed != frame->frameNumber + 1);
         framesPlayed = frame->frameNumber + 1;
