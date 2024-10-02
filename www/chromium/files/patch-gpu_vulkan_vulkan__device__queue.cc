--- gpu/vulkan/vulkan_device_queue.cc.orig	2024-09-30 07:45:04 UTC
+++ gpu/vulkan/vulkan_device_queue.cc
@@ -154,7 +154,7 @@ bool VulkanDeviceQueue::Initialize(
 
       // In dual-CPU cases, we cannot detect the active GPU correctly on Linux,
       // so don't select GPU device based on the |gpu_info|.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // If gpu_info is provided, the device should match it.
     if (gpu_info && (device_properties.vendorID != gpu_info->gpu.vendor_id ||
                      device_properties.deviceID != gpu_info->gpu.device_id)) {
@@ -297,7 +297,7 @@ bool VulkanDeviceQueue::Initialize(
   // Android, Fuchsia, Linux, and CrOS (VaapiVideoDecoder) need YCbCr sampler
   // support.
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!physical_device_info.feature_sampler_ycbcr_conversion) {
     LOG(ERROR) << "samplerYcbcrConversion is not supported.";
     return false;
