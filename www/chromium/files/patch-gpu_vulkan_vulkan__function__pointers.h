--- gpu/vulkan/vulkan_function_pointers.h.orig	2020-07-07 21:58:16 UTC
+++ gpu/vulkan/vulkan_function_pointers.h
@@ -235,10 +235,10 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFunctionPointers
       vkGetAndroidHardwareBufferPropertiesANDROIDFn;
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetSemaphoreFdKHR> vkGetSemaphoreFdKHRFn;
   VulkanFunction<PFN_vkImportSemaphoreFdKHR> vkImportSemaphoreFdKHRFn;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   VulkanFunction<PFN_vkGetSemaphoreWin32HandleKHR>
@@ -247,10 +247,10 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFunctionPointers
       vkImportSemaphoreWin32HandleKHRFn;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetMemoryFdKHR> vkGetMemoryFdKHRFn;
   VulkanFunction<PFN_vkGetMemoryFdPropertiesKHR> vkGetMemoryFdPropertiesKHRFn;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   VulkanFunction<PFN_vkGetMemoryWin32HandleKHR> vkGetMemoryWin32HandleKHRFn;
@@ -950,7 +950,7 @@ ALWAYS_INLINE VkResult vkGetAndroidHardwareBufferPrope
 }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 ALWAYS_INLINE VkResult
 vkGetSemaphoreFdKHR(VkDevice device,
                     const VkSemaphoreGetFdInfoKHR* pGetFdInfo,
@@ -964,7 +964,7 @@ ALWAYS_INLINE VkResult vkImportSemaphoreFdKHR(
   return gpu::GetVulkanFunctionPointers()->vkImportSemaphoreFdKHRFn(
       device, pImportSemaphoreFdInfo);
 }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 ALWAYS_INLINE VkResult vkGetSemaphoreWin32HandleKHR(
@@ -983,7 +983,7 @@ vkImportSemaphoreWin32HandleKHR(VkDevice device,
 }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 ALWAYS_INLINE VkResult vkGetMemoryFdKHR(VkDevice device,
                                         const VkMemoryGetFdInfoKHR* pGetFdInfo,
                                         int* pFd) {
@@ -998,7 +998,7 @@ vkGetMemoryFdPropertiesKHR(VkDevice device,
   return gpu::GetVulkanFunctionPointers()->vkGetMemoryFdPropertiesKHRFn(
       device, handleType, fd, pMemoryFdProperties);
 }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 ALWAYS_INLINE VkResult vkGetMemoryWin32HandleKHR(
@@ -1079,4 +1079,4 @@ ALWAYS_INLINE VkResult vkQueuePresentKHR(VkQueue queue
                                                                pPresentInfo);
 }
 
-#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
\ No newline at end of file
+#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
