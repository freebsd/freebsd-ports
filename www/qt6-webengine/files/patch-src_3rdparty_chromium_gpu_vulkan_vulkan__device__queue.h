--- src/3rdparty/chromium/gpu/vulkan/vulkan_device_queue.h.orig	2022-09-24 10:57:32 UTC
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_device_queue.h
@@ -158,7 +158,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanDeviceQueue {
 
   bool allow_protected_memory_ = false;
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   VkPhysicalDeviceSamplerYcbcrConversionFeatures
       sampler_ycbcr_conversion_features_{
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES};
