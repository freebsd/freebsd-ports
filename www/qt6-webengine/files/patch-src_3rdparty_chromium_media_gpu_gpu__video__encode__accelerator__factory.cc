--- src/3rdparty/chromium/media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -121,7 +121,7 @@ std::vector<VEAFactoryFunction> GetVEAFactoryFunctions
     return vea_factory_functions;
 
 #if BUILDFLAG(USE_VAAPI)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kVaapiVideoEncodeLinux))
     vea_factory_functions.push_back(base::BindRepeating(&CreateVaapiVEA));
 #else
