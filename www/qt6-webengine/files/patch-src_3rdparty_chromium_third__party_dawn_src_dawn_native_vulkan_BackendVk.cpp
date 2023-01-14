--- src/3rdparty/chromium/third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -37,7 +37,7 @@ constexpr char kSwiftshaderLibName[] = "libvk_swiftsha
 #endif
 
 #if defined(DAWN_PLATFORM_LINUX)
-#    if defined(DAWN_PLATFORM_ANDROID)
+#    if defined(DAWN_PLATFORM_ANDROID) || defined(DAWN_PLATFORM_BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #    else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";
