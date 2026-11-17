--- src/gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2026-10-18 18:43:23 UTC
+++ src/gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -158,7 +158,7 @@ bool IsFormatSupported(viz::SharedImageF
 
 SharedImageUsageSet SupportedUsage() {
   SharedImageUsageSet supported_usage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
       SHARED_IMAGE_USAGE_WEBGPU_READ | SHARED_IMAGE_USAGE_WEBGPU_WRITE |
       SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
       SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
