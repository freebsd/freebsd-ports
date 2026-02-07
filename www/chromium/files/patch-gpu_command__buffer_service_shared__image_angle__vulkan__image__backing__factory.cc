--- gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc.orig	2025-12-05 10:12:50 UTC
+++ gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc
@@ -20,7 +20,7 @@ namespace {
 // TODO(penghuang): verify the scanout is the right usage for video playback.
 // crbug.com/1280798
 constexpr SharedImageUsageSet kSupportedUsage =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     SHARED_IMAGE_USAGE_SCANOUT |
 #endif
     SHARED_IMAGE_USAGE_GLES2_READ | SHARED_IMAGE_USAGE_GLES2_WRITE |
@@ -119,7 +119,7 @@ bool AngleVulkanImageBackingFactory::IsGMBSupported(
   switch (gmb_type) {
     case gfx::EMPTY_BUFFER:
       return true;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case gfx::NATIVE_PIXMAP: {
       auto* vulkan_implementation =
           context_state_->vk_context_provider()->GetVulkanImplementation();
