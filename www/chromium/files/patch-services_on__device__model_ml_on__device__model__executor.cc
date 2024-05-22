--- services/on_device_model/ml/on_device_model_executor.cc.orig	2024-05-21 18:07:39 UTC
+++ services/on_device_model/ml/on_device_model_executor.cc
@@ -60,7 +60,7 @@ const base::FeatureParam<bool> kAllowFp16{
     &optimization_guide::features::kOptimizationGuideOnDeviceModel,
     "on_device_model_allow_fp16",
 // TODO(b/333406033): Fix Linux fp16 issues.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     false
 #else
     true
