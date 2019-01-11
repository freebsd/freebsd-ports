--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2019-01-09 13:04:56.177184000 +0100
+++ media/video/gpu_memory_buffer_video_frame_pool.cc	2019-01-09 13:05:16.072782000 +0100
@@ -633,7 +633,7 @@
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
