--- third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2025-04-15 08:30:07 UTC
+++ third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -57,7 +57,7 @@ constexpr char kSwiftshaderLibName[] = "libvk_swiftsha
 #endif
 
 #if DAWN_PLATFORM_IS(LINUX)
-#if DAWN_PLATFORM_IS(ANDROID)
+#if DAWN_PLATFORM_IS(ANDROID) || DAWN_PLATFORM_IS(BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";
