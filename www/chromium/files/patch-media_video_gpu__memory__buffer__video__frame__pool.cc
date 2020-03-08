--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2020-03-03 18:53:55 UTC
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -572,7 +572,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
