--- gpu/vulkan/vulkan_function_pointers.h.orig	2020-11-13 06:36:44 UTC
+++ gpu/vulkan/vulkan_function_pointers.h
@@ -236,10 +236,10 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFunctionPointers
       vkGetAndroidHardwareBufferPropertiesANDROID;
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetSemaphoreFdKHR> vkGetSemaphoreFdKHR;
   VulkanFunction<PFN_vkImportSemaphoreFdKHR> vkImportSemaphoreFdKHR;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   VulkanFunction<PFN_vkGetSemaphoreWin32HandleKHR> vkGetSemaphoreWin32HandleKHR;
@@ -247,10 +247,10 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFunctionPointers
       vkImportSemaphoreWin32HandleKHR;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetMemoryFdKHR> vkGetMemoryFdKHR;
   VulkanFunction<PFN_vkGetMemoryFdPropertiesKHR> vkGetMemoryFdPropertiesKHR;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   VulkanFunction<PFN_vkGetMemoryWin32HandleKHR> vkGetMemoryWin32HandleKHR;
@@ -955,7 +955,7 @@ ALWAYS_INLINE VkResult vkGetAndroidHardwareBufferPrope
 }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 ALWAYS_INLINE VkResult
 vkGetSemaphoreFdKHR(VkDevice device,
                     const VkSemaphoreGetFdInfoKHR* pGetFdInfo,
@@ -969,7 +969,7 @@ ALWAYS_INLINE VkResult vkImportSemaphoreFdKHR(
   return gpu::GetVulkanFunctionPointers()->vkImportSemaphoreFdKHR(
       device, pImportSemaphoreFdInfo);
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 ALWAYS_INLINE VkResult vkGetSemaphoreWin32HandleKHR(
@@ -988,7 +988,7 @@ vkImportSemaphoreWin32HandleKHR(VkDevice device,
 }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 ALWAYS_INLINE VkResult vkGetMemoryFdKHR(VkDevice device,
                                         const VkMemoryGetFdInfoKHR* pGetFdInfo,
                                         int* pFd) {
@@ -1003,7 +1003,7 @@ vkGetMemoryFdPropertiesKHR(VkDevice device,
   return gpu::GetVulkanFunctionPointers()->vkGetMemoryFdPropertiesKHR(
       device, handleType, fd, pMemoryFdProperties);
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 ALWAYS_INLINE VkResult vkGetMemoryWin32HandleKHR(
@@ -1083,4 +1083,4 @@ ALWAYS_INLINE VkResult vkQueuePresentKHR(VkQueue queue
                                                              pPresentInfo);
 }
 
-#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
\ No newline at end of file
+#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
