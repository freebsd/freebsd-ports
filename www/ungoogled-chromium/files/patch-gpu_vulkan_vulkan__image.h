--- gpu/vulkan/vulkan_image.h.orig	2025-09-10 13:22:16 UTC
+++ gpu/vulkan/vulkan_image.h
@@ -86,7 +86,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanImage {
       VkImageUsageFlags usage,
       VkImageCreateFlags flags);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<VulkanImage> CreateWithExternalMemoryAndModifiers(
       VulkanDeviceQueue* device_queue,
       const gfx::Size& size,
@@ -198,7 +198,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanImage {
       VkImageTiling image_tiling,
       uint32_t queue_family_index);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool InitializeWithExternalMemoryAndModifiers(VulkanDeviceQueue* device_queue,
                                                 const gfx::Size& size,
                                                 VkFormat format,
