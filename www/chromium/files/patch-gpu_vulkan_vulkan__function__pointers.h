--- gpu/vulkan/vulkan_function_pointers.h.orig	2019-12-16 21:50:48 UTC
+++ gpu/vulkan/vulkan_function_pointers.h
@@ -178,15 +178,15 @@ struct VulkanFunctionPointers {
       vkGetAndroidHardwareBufferPropertiesANDROIDFn = nullptr;
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHRFn = nullptr;
   PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHRFn = nullptr;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   PFN_vkGetMemoryFdKHR vkGetMemoryFdKHRFn = nullptr;
   PFN_vkGetMemoryFdPropertiesKHR vkGetMemoryFdPropertiesKHRFn = nullptr;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_FUCHSIA)
   PFN_vkImportSemaphoreZirconHandleFUCHSIA
@@ -374,18 +374,18 @@ struct VulkanFunctionPointers {
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
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #define vkGetMemoryFdKHR gpu::GetVulkanFunctionPointers()->vkGetMemoryFdKHRFn
 #define vkGetMemoryFdPropertiesKHR \
   gpu::GetVulkanFunctionPointers()->vkGetMemoryFdPropertiesKHRFn
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_FUCHSIA)
 #define vkImportSemaphoreZirconHandleFUCHSIA \
