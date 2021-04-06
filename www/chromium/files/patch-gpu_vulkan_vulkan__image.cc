--- gpu/vulkan/vulkan_image.cc.orig	2021-03-12 23:57:25 UTC
+++ gpu/vulkan/vulkan_image.cc
@@ -320,7 +320,7 @@ bool VulkanImage::InitializeWithExternalMemory(
   };
   format_info_2.pNext = &external_info;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   VkPhysicalDeviceImageDrmFormatModifierInfoEXT modifier_info = {
       .sType =
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT,
