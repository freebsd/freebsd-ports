--- media/video/mappable_shared_image_video_frame_pool.cc.orig	2026-08-31 10:59:09 UTC
+++ media/video/mappable_shared_image_video_frame_pool.cc
@@ -683,7 +683,7 @@ void MappableSharedImageVideoFramePool::PoolImpl::Crea
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1109,7 +1109,7 @@ scoped_refptr<VideoFrame> MappableSharedImageVideoFram
           gpu::SHARED_IMAGE_USAGE_WEBGPU_READ);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Gate this on SharedImage usage as ScopedAccess now CHECKs for it.
   // TOOD(crbug.com/425634684, crbug.com/413659843): Check for webgpu support
   // from SharedImageCapabilities, once this metadata is compatible.
