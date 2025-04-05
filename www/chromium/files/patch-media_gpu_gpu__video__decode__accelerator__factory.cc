--- media/gpu/gpu_video_decode_accelerator_factory.cc.orig	2025-04-04 08:52:13 UTC
+++ media/gpu/gpu_video_decode_accelerator_factory.cc
@@ -12,7 +12,7 @@
 #include "media/gpu/media_gpu_export.h"
 #include "media/media_buildflags.h"
 
-#if BUILDFLAG(USE_V4L2_CODEC) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(USE_V4L2_CODEC) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #include "media/gpu/v4l2/legacy/v4l2_video_decode_accelerator.h"
 #include "media/gpu/v4l2/v4l2_device.h"
 #endif
@@ -28,7 +28,7 @@ GpuVideoDecodeAcceleratorFactory::CreateVDA(
   if (gpu_preferences.disable_accelerated_video_decode)
     return nullptr;
 
-#if BUILDFLAG(USE_V4L2_CODEC) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(USE_V4L2_CODEC) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 
   std::unique_ptr<VideoDecodeAccelerator> vda;
   vda.reset(new V4L2VideoDecodeAccelerator(new V4L2Device()));
