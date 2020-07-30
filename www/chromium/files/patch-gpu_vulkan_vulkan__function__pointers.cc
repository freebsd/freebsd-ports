--- gpu/vulkan/vulkan_function_pointers.cc.orig	2020-07-07 21:58:16 UTC
+++ gpu/vulkan/vulkan_function_pointers.cc
@@ -862,7 +862,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
   }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME)) {
     vkGetSemaphoreFdKHRFn = reinterpret_cast<PFN_vkGetSemaphoreFdKHR>(
@@ -881,7 +881,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
       return false;
     }
   }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   if (gfx::HasExtension(enabled_extensions,
@@ -906,7 +906,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
   }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME)) {
     vkGetMemoryFdKHRFn = reinterpret_cast<PFN_vkGetMemoryFdKHR>(
@@ -926,7 +926,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
       return false;
     }
   }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   if (gfx::HasExtension(enabled_extensions,
