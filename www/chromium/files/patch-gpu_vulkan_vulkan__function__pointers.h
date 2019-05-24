--- gpu/vulkan/vulkan_function_pointers.h.orig	2019-05-04 12:16:20 UTC
+++ gpu/vulkan/vulkan_function_pointers.h
@@ -114,12 +114,12 @@ struct VulkanFunctionPointers {
 #endif
 
   // Device functions shared between Linux and Android.
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHRFn = nullptr;
 #endif
 
   // Linux-only device functions.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   PFN_vkGetMemoryFdKHR vkGetMemoryFdKHRFn = nullptr;
 #endif
 
@@ -245,12 +245,12 @@ struct VulkanFunctionPointers {
   gpu::GetVulkanFunctionPointers()->vkImportSemaphoreFdKHRFn
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #define vkGetSemaphoreFdKHR \
   gpu::GetVulkanFunctionPointers()->vkGetSemaphoreFdKHRFn
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #define vkGetMemoryFdKHR gpu::GetVulkanFunctionPointers()->vkGetMemoryFdKHRFn
 #endif
 
