--- services/on_device_model/ml/gpu_blocklist.cc.orig	2025-12-10 15:04:57 UTC
+++ services/on_device_model/ml/gpu_blocklist.cc
@@ -24,7 +24,7 @@ const base::FeatureParam<std::string> kGpuBlockList{
     &optimization_guide::features::kOnDeviceModelPerformanceParams,
     "on_device_model_gpu_block_list",
     // These devices are nearly always crashing or have very low performance.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "8086:64a0|8086:e20b|"  // TODO(b/456603738): Remove when fixed.
 #endif  // BUILDFLAG(IS_LINUX)
     "8086:412|8086:a16|8086:41e|8086:416|8086:402|8086:166|8086:1616|8086:22b1|"
