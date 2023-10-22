--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2023-11-22 14:00:11 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -99,7 +99,7 @@ base::flat_map<VkFormat, VkImageUsageFlags> CreateImag
 }  // namespace
 
 constexpr uint32_t kSupportedUsage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
     SHARED_IMAGE_USAGE_WEBGPU | SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
     SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
 #endif
@@ -268,7 +268,7 @@ bool ExternalVkImageBackingFactory::IsSupported(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (format.IsLegacyMultiplanar()) {
     // ExternalVkImageBacking doesn't work properly with external sampler
     // multi-planar formats on Linux, see https://crbug.com/1394888.
