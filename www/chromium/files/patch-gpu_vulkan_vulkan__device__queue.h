--- gpu/vulkan/vulkan_device_queue.h.orig	2022-02-28 16:54:41 UTC
+++ gpu/vulkan/vulkan_device_queue.h
@@ -155,7 +155,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanDeviceQueue {
 
   bool allow_protected_memory_ = false;
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   VkPhysicalDeviceSamplerYcbcrConversionFeatures
       sampler_ycbcr_conversion_features_{
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES};
