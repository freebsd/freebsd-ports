--- src/3rdparty/chromium/ui/ozone/platform/headless/vulkan_implementation_headless.cc.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/headless/vulkan_implementation_headless.cc
@@ -155,7 +155,7 @@ VulkanImplementationHeadless::CreateImageFromGpuMemory
       VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT |
       VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
   auto tiling = VK_IMAGE_TILING_OPTIMAL;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (gmb_handle.native_pixmap_handle.modifier !=
       gfx::NativePixmapHandle::kNoModifier) {
     tiling = VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT;
