--- gpu/vulkan/vulkan_function_pointers.h.orig	2019-06-04 18:55:24 UTC
+++ gpu/vulkan/vulkan_function_pointers.h
@@ -131,13 +131,13 @@ struct VulkanFunctionPointers {
 #endif
 
   // Device functions shared between Linux and Android.
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHRFn = nullptr;
   PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHRFn = nullptr;
 #endif
 
   // Linux-only device functions.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   PFN_vkGetMemoryFdKHR vkGetMemoryFdKHRFn = nullptr;
 #endif
 
@@ -286,14 +286,14 @@ struct VulkanFunctionPointers {
       ->vkGetAndroidHardwareBufferPropertiesANDROIDFn
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #define vkGetSemaphoreFdKHR \
   gpu::GetVulkanFunctionPointers()->vkGetSemaphoreFdKHRFn
 #define vkImportSemaphoreFdKHR \
   gpu::GetVulkanFunctionPointers()->vkImportSemaphoreFdKHRFn
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #define vkGetMemoryFdKHR gpu::GetVulkanFunctionPointers()->vkGetMemoryFdKHRFn
 #endif
 
