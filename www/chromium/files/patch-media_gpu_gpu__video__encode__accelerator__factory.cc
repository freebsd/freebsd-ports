--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2021-04-22 08:21:56 UTC
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -93,7 +93,7 @@ std::vector<VEAFactoryFunction> GetVEAFactoryFunctions
     return vea_factory_functions;
 
 #if BUILDFLAG(USE_VAAPI)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(kVaapiVideoEncodeLinux))
     vea_factory_functions.push_back(base::BindRepeating(&CreateVaapiVEA));
 #else
