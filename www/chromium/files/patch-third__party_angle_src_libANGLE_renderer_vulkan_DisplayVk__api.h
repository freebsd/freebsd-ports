--- third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h.orig	2020-02-03 21:54:48 UTC
+++ third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h
@@ -19,10 +19,10 @@ bool IsVulkanWin32DisplayAvailable();
 DisplayImpl *CreateVulkanWin32Display(const egl::DisplayState &state);
 #endif  // defined(ANGLE_PLATFORM_WINDOWS)
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool IsVulkanXcbDisplayAvailable();
 DisplayImpl *CreateVulkanXcbDisplay(const egl::DisplayState &state);
-#endif  // defined(ANGLE_PLATFORM_LINUX)
+#endif  // defined(ANGLE_PLATFORM_POSIX)
 
 #if defined(ANGLE_PLATFORM_ANDROID)
 bool IsVulkanAndroidDisplayAvailable();
