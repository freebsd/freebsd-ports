--- third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h.orig	2025-12-10 15:04:57 UTC
+++ third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h
@@ -23,7 +23,7 @@ bool IsVulkanWin32DisplayAvailable();
 DisplayImpl *CreateVulkanWin32Display(const egl::DisplayState &state);
 #endif  // defined(ANGLE_PLATFORM_WINDOWS)
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool IsVulkanWaylandDisplayAvailable();
 DisplayImpl *CreateVulkanWaylandDisplay(const egl::DisplayState &state);
 
