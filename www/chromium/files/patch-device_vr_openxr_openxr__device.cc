--- device/vr/openxr/openxr_device.cc.orig	2026-09-25 15:26:43 UTC
+++ device/vr/openxr/openxr_device.cc
@@ -90,7 +90,7 @@ OpenXrDevice::OpenXrDevice(
 
   // Only support WebGPU sessions if the feature flag is enabled; the Linux
   // Vulkan binding does not support WebGPU sessions yet.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kWebXRWebGPUBinding)) {
     device_data.supported_features.emplace_back(
         mojom::XRSessionFeature::WEBGPU);
