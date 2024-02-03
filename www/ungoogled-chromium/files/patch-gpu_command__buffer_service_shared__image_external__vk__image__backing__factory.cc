--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2024-02-03 15:42:55 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -139,7 +139,7 @@ bool IsFormatSupported(viz::SharedImageFormat format,
 }  // namespace
 
 constexpr uint32_t kSupportedUsage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
     SHARED_IMAGE_USAGE_WEBGPU | SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
     SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
 #endif
