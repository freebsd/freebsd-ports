--- libs/libmythtv/videoout_vdpau.cpp.orig	2010-02-27 06:58:11.000000000 +0100
+++ libs/libmythtv/videoout_vdpau.cpp	2010-04-06 17:40:50.000000000 +0200
@@ -395,7 +395,7 @@
     if (frame)
     {
         // FIXME for 0.23. This should be triggered from AFD by a seek
-        if ((abs(frame->frameNumber - framesPlayed) > 8))
+        if ((labs(frame->frameNumber - framesPlayed) > 8))
             ClearReferenceFrames();
         new_frame = (framesPlayed != frame->frameNumber + 1);
         framesPlayed = frame->frameNumber + 1;
