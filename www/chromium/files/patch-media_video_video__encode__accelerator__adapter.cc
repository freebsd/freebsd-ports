--- media/video/video_encode_accelerator_adapter.cc.orig	2026-10-18 13:29:39 UTC
+++ media/video/video_encode_accelerator_adapter.cc
@@ -277,7 +277,7 @@ class VideoEncodeAcceleratorAdapter::MappableSharedIma
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
     DCHECK(gfx::Rect(coded_size_).Contains(gfx::Rect(visible_size)));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     const auto buffer_usage =
         gfx::BufferUsage::VEA_READ_CAMERA_AND_CPU_READ_WRITE;
 #else
@@ -607,7 +607,7 @@ void VideoEncodeAcceleratorAdapter::InitializeOnAccele
 #endif  // BUILDFLAG(USE_PROPRIETARY_CODECS)
 
   auto storage_type = VideoEncodeAccelerator::Config::StorageType::kShmem;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Linux/ChromeOS require a special configuration to use dmabuf storage.
   // We need to keep sending frames with the same storage type.
   // Other platforms will happily mix GpuMemoryBuffer storage with shared-mem
