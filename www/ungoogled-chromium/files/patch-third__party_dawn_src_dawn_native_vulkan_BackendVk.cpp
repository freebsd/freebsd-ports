--- third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2023-12-23 12:33:28 UTC
+++ third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -55,7 +55,7 @@ constexpr char kSwiftshaderLibName[] = "libvk_swiftsha
 #endif
 
 #if DAWN_PLATFORM_IS(LINUX)
-#if DAWN_PLATFORM_IS(ANDROID)
+#if DAWN_PLATFORM_IS(ANDROID) || DAWN_PLATFORM_IS(BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";
