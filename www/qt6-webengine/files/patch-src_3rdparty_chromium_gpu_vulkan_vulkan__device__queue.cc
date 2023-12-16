--- src/3rdparty/chromium/gpu/vulkan/vulkan_device_queue.cc.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_device_queue.cc
@@ -89,7 +89,7 @@ bool VulkanDeviceQueue::Initialize(
 
       // In dual-CPU cases, we cannot detect the active GPU correctly on Linux,
       // so don't select GPU device based on the |gpu_info|.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // If gpu_info is provided, the device should match it.
     if (gpu_info && (device_properties.vendorID != gpu_info->gpu.vendor_id ||
                      device_properties.deviceID != gpu_info->gpu.device_id)) {
@@ -229,7 +229,7 @@ bool VulkanDeviceQueue::Initialize(
   enabled_device_features_2_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2};
 
   // Android, Fuchsia, and Linux(VaapiVideoDecoder) need YCbCr sampler support.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!physical_device_info.feature_sampler_ycbcr_conversion) {
     LOG(ERROR) << "samplerYcbcrConversion is not supported.";
     return false;
