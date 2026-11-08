--- src/3rdparty/chromium/media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -155,7 +155,7 @@ std::vector<VEAFactoryFunction> CreateVEAFactoryFuncti
     const gpu::GPUInfo::GPUDevice& gpu_device) {
   std::vector<VEAFactoryFunction> funcs;
 #if BUILDFLAG(USE_VAAPI)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     funcs.push_back(base::BindRepeating(&CreateVaapiVEA));
   }
@@ -163,7 +163,7 @@ std::vector<VEAFactoryFunction> CreateVEAFactoryFuncti
   funcs.push_back(base::BindRepeating(&CreateVaapiVEA));
 #endif
 #elif BUILDFLAG(USE_V4L2_CODEC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     funcs.push_back(base::BindRepeating(&CreateV4L2VEA));
   }
