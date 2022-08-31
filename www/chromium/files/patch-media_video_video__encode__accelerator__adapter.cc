--- media/video/video_encode_accelerator_adapter.cc.orig	2022-08-31 12:19:35 UTC
+++ media/video/video_encode_accelerator_adapter.cc
@@ -128,7 +128,7 @@ VideoEncodeAccelerator::Config SetUpVeaConfig(
   if (is_rgb)
     config.input_format = PIXEL_FORMAT_I420;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (storage_type == VideoFrame::STORAGE_DMABUFS ||
       storage_type == VideoFrame::STORAGE_GPU_MEMORY_BUFFER) {
     if (is_rgb)
@@ -297,7 +297,7 @@ void VideoEncodeAcceleratorAdapter::InitializeInternal
       SetUpVeaConfig(profile_, options_, format, first_frame->storage_type(),
                      supported_rc_modes_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Linux/ChromeOS require a special configuration to use dmabuf storage.
   // We need to keep sending frames the same way the first frame was sent.
   // Other platforms will happily mix GpuMemoryBuffer storage with regular
