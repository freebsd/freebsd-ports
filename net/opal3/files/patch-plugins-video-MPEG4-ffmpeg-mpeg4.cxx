--- plugins/video/MPEG4-ffmpeg/mpeg4.cxx.orig	2011-06-25 11:31:14.153034898 +0200
+++ plugins/video/MPEG4-ffmpeg/mpeg4.cxx	2011-06-25 11:32:04.791577475 +0200
@@ -830,10 +830,10 @@
         {
             _avpicture->pict_type = FF_I_TYPE;
         }
         else // No IFrame requested, let avcodec decide what to do
         {
-            _avpicture->pict_type = 0;
+            _avpicture->pict_type = AV_PICTURE_TYPE_NONE;
         }
 
         // Encode a frame
         int total = FFMPEGLibraryInstance.AvcodecEncodeVideo
