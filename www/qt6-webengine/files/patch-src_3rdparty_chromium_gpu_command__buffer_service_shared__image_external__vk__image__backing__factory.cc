--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -89,7 +89,7 @@ constexpr uint32_t kSupportedUsage =
 }  // namespace
 
 constexpr uint32_t kSupportedUsage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
     SHARED_IMAGE_USAGE_WEBGPU | SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
     SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
 #endif
@@ -258,7 +258,7 @@ bool ExternalVkImageBackingFactory::IsSupported(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(TOOLKIT_QT)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(TOOLKIT_QT)
   if (format.IsLegacyMultiplanar()) {
     // ExternalVkImageBacking doesn't work properly with external sampler
     // multi-planar formats on Linux, see https://crbug.com/1394888.
