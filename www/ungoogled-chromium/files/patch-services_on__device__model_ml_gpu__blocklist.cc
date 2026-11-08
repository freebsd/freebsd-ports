--- services/on_device_model/ml/gpu_blocklist.cc.orig	2026-08-13 07:41:05 UTC
+++ services/on_device_model/ml/gpu_blocklist.cc
@@ -23,7 +23,7 @@ namespace {
 const base::FeatureParam<std::string> kGpuBlockList{
     &optimization_guide::features::kOnDeviceModelPerformanceParams,
     "on_device_model_gpu_block_list",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "8086:64a0|8086:e20b|"  // TODO(b/456603738): Remove when fixed.
 #endif  // BUILDFLAG(IS_LINUX)
     // These devices are nearly always crashing or have very low performance.
