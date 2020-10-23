--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2020-09-08 19:14:07 UTC
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -573,7 +573,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
