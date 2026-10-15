--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-08-31 10:59:09 UTC
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -71,7 +71,7 @@ std::unique_ptr<VideoEncodeAccelerator> CreateV4L2VEA(
 
 #if BUILDFLAG(USE_VAAPI)
 std::unique_ptr<VideoEncodeAccelerator> CreateVaapiVEA() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     return nullptr;
   }
