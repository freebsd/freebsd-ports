--- src/3rdparty/chromium/media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -633,7 +633,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
