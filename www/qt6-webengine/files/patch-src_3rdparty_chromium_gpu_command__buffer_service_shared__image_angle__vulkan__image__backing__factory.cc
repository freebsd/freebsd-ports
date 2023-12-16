--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc
@@ -20,7 +20,7 @@ namespace {
 // TODO(penghuang): verify the scanout is the right usage for video playback.
 // crbug.com/1280798
 constexpr uint32_t kSupportedUsage =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     SHARED_IMAGE_USAGE_SCANOUT |
 #endif
     SHARED_IMAGE_USAGE_GLES2 | SHARED_IMAGE_USAGE_GLES2_FRAMEBUFFER_HINT |
