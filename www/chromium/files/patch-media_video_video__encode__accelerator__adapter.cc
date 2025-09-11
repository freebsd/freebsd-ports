--- media/video/video_encode_accelerator_adapter.cc.orig	2025-09-06 10:01:20 UTC
+++ media/video/video_encode_accelerator_adapter.cc
@@ -467,7 +467,7 @@ void VideoEncodeAcceleratorAdapter::InitializeOnAccele
 
   auto format = PIXEL_FORMAT_I420;
   auto storage_type = VideoEncodeAccelerator::Config::StorageType::kShmem;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Linux/ChromeOS require a special configuration to use dmabuf storage.
   // We need to keep sending frames with the same storage type.
   // Other platforms will happily mix GpuMemoryBuffer storage with shared-mem
