--- content/renderer/render_thread_impl.cc.orig	2016-07-20 22:03:24.000000000 +0300
+++ content/renderer/render_thread_impl.cc	2016-08-01 04:09:35.329085000 +0300
@@ -1424,7 +1424,7 @@
   const bool enable_video_accelerator =
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode);
   const bool enable_gpu_memory_buffer_video_frames =
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames) &&
       !cmd_line->HasSwitch(switches::kDisableGpuCompositing) &&
       !gpu_channel_host->gpu_info().software_rendering;
