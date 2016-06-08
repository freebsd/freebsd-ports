--- content/renderer/render_thread_impl.cc.orig	2016-05-25 15:01:02.000000000 -0400
+++ content/renderer/render_thread_impl.cc	2016-05-27 11:01:14.634236000 -0400
@@ -1468,7 +1468,7 @@
     const bool enable_video_accelerator =
         !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode);
     const bool enable_gpu_memory_buffer_video_frames =
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames) &&
         !cmd_line->HasSwitch(switches::kDisableGpuCompositing) &&
         !gpu_channel_host->gpu_info().software_rendering;
