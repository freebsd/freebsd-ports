--- media/video/mappable_shared_image_video_frame_pool.cc.orig	2026-09-25 15:26:43 UTC
+++ media/video/mappable_shared_image_video_frame_pool.cc
@@ -685,7 +685,7 @@ void MappableSharedImageVideoFramePool::PoolImpl::Crea
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
