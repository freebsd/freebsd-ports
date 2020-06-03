--- gpu/vulkan/vulkan_function_pointers.h.orig	2020-05-13 18:40:32 UTC
+++ gpu/vulkan/vulkan_function_pointers.h
@@ -227,15 +227,15 @@ struct VulkanFunctionPointers {
       vkGetAndroidHardwareBufferPropertiesANDROIDFn;
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetSemaphoreFdKHR> vkGetSemaphoreFdKHRFn;
   VulkanFunction<PFN_vkImportSemaphoreFdKHR> vkImportSemaphoreFdKHRFn;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetMemoryFdKHR> vkGetMemoryFdKHRFn;
   VulkanFunction<PFN_vkGetMemoryFdPropertiesKHR> vkGetMemoryFdPropertiesKHRFn;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_FUCHSIA)
   VulkanFunction<PFN_vkImportSemaphoreZirconHandleFUCHSIA>
@@ -447,18 +447,18 @@ struct VulkanFunctionPointers {
       ->vkGetAndroidHardwareBufferPropertiesANDROIDFn
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #define vkGetSemaphoreFdKHR \
   gpu::GetVulkanFunctionPointers()->vkGetSemaphoreFdKHRFn
 #define vkImportSemaphoreFdKHR \
   gpu::GetVulkanFunctionPointers()->vkImportSemaphoreFdKHRFn
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #define vkGetMemoryFdKHR gpu::GetVulkanFunctionPointers()->vkGetMemoryFdKHRFn
 #define vkGetMemoryFdPropertiesKHR \
   gpu::GetVulkanFunctionPointers()->vkGetMemoryFdPropertiesKHRFn
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_FUCHSIA)
 #define vkImportSemaphoreZirconHandleFUCHSIA \
@@ -493,4 +493,4 @@ struct VulkanFunctionPointers {
   gpu::GetVulkanFunctionPointers()->vkGetSwapchainImagesKHRFn
 #define vkQueuePresentKHR gpu::GetVulkanFunctionPointers()->vkQueuePresentKHRFn
 
-#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
\ No newline at end of file
+#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
