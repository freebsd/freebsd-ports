--- third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h.orig	2021-01-18 21:31:44 UTC
+++ third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h
@@ -19,13 +19,13 @@ bool IsVulkanWin32DisplayAvailable();
 DisplayImpl *CreateVulkanWin32Display(const egl::DisplayState &state);
 #endif  // defined(ANGLE_PLATFORM_WINDOWS)
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool IsVulkanXcbDisplayAvailable();
 DisplayImpl *CreateVulkanXcbDisplay(const egl::DisplayState &state);
 
 bool IsVulkanSimpleDisplayAvailable();
 DisplayImpl *CreateVulkanSimpleDisplay(const egl::DisplayState &state);
-#endif  // defined(ANGLE_PLATFORM_LINUX)
+#endif  // defined(ANGLE_PLATFORM_POSIX)
 
 #if defined(ANGLE_PLATFORM_ANDROID)
 bool IsVulkanAndroidDisplayAvailable();
