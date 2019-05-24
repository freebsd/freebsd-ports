--- gpu/vulkan/vulkan_function_pointers.cc.orig	2019-04-30 22:22:49 UTC
+++ gpu/vulkan/vulkan_function_pointers.cc
@@ -310,7 +310,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
 
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
   vkGetSemaphoreFdKHRFn = reinterpret_cast<PFN_vkGetSemaphoreFdKHR>(
       vkGetDeviceProcAddrFn(vk_device, "vkGetSemaphoreFdKHR"));
@@ -319,7 +319,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
 
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
   vkGetMemoryFdKHRFn = reinterpret_cast<PFN_vkGetMemoryFdKHR>(
       vkGetDeviceProcAddrFn(vk_device, "vkGetMemoryFdKHR"));
