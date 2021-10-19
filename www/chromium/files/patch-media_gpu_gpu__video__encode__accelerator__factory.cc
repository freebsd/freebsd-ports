--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2021-09-14 01:51:59 UTC
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -94,7 +94,7 @@ std::vector<VEAFactoryFunction> GetVEAFactoryFunctions
     return vea_factory_functions;
 
 #if BUILDFLAG(USE_VAAPI)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(kVaapiVideoEncodeLinux))
     vea_factory_functions.push_back(base::BindRepeating(&CreateVaapiVEA));
 #else
