--- media/gfx/mappable_shared_image_video_frame_pool.cc.orig	2026-10-18 13:29:39 UTC
+++ media/gfx/mappable_shared_image_video_frame_pool.cc
@@ -684,7 +684,7 @@ void MappableSharedImageVideoFramePool::PoolImpl::Crea
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
