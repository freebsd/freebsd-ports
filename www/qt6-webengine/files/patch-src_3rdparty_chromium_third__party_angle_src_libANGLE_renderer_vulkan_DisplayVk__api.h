--- src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h
@@ -23,7 +23,7 @@ DisplayImpl *CreateVulkanWin32Display(const egl::Displ
 DisplayImpl *CreateVulkanWin32Display(const egl::DisplayState &state);
 #endif  // defined(ANGLE_PLATFORM_WINDOWS)
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool IsVulkanWaylandDisplayAvailable();
 DisplayImpl *CreateVulkanWaylandDisplay(const egl::DisplayState &state);
 
