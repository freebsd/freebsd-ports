--- src/3rdparty/chromium/media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -795,7 +795,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
