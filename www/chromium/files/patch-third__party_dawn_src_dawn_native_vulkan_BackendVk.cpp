--- third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2022-06-17 14:20:10 UTC
+++ third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -41,7 +41,7 @@ constexpr char kSwiftshaderLibName[] = "libvk_swiftsha
 #endif
 
 #if defined(DAWN_PLATFORM_LINUX)
-#if defined(DAWN_PLATFORM_ANDROID)
+#if defined(DAWN_PLATFORM_ANDROID) || defined(DAWN_PLATFORM_BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";
