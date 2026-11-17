--- src/media/video/mappable_shared_image_video_frame_pool.cc.orig	2026-10-18 18:43:23 UTC
+++ src/media/video/mappable_shared_image_video_frame_pool.cc
@@ -684,7 +684,7 @@ void MappableSharedImageVideoFramePool::
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
