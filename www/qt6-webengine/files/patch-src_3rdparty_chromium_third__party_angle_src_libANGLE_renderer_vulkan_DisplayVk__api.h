--- src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h
@@ -23,7 +23,7 @@ DisplayImpl *CreateVulkanWin32Display(const egl::Displ
 DisplayImpl *CreateVulkanWin32Display(const egl::DisplayState &state);
 #endif  // defined(ANGLE_PLATFORM_WINDOWS)
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool IsVulkanXcbDisplayAvailable();
 DisplayImpl *CreateVulkanXcbDisplay(const egl::DisplayState &state);
 
