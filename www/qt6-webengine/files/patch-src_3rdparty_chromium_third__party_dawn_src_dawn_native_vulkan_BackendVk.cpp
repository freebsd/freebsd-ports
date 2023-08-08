--- src/3rdparty/chromium/third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -42,7 +42,7 @@ constexpr char kSwiftshaderLibName[] = "libvk_swiftsha
 #endif
 
 #if DAWN_PLATFORM_IS(LINUX)
-#if DAWN_PLATFORM_IS(ANDROID)
+#if DAWN_PLATFORM_IS(ANDROID) || DAWN_PLATFORM_IS(BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";
