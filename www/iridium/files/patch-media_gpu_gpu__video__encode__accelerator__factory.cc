--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-02-16 10:45:29 UTC
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -67,7 +67,7 @@ std::unique_ptr<VideoEncodeAccelerator> CreateV4L2VEA(
 }
 #elif BUILDFLAG(USE_VAAPI)
 std::unique_ptr<VideoEncodeAccelerator> CreateVaapiVEA() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     return nullptr;
   }
