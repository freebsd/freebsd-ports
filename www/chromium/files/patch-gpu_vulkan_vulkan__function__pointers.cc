--- gpu/vulkan/vulkan_function_pointers.cc.orig	2019-12-16 21:50:48 UTC
+++ gpu/vulkan/vulkan_function_pointers.cc
@@ -772,7 +772,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
   }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME)) {
     vkGetSemaphoreFdKHRFn = reinterpret_cast<PFN_vkGetSemaphoreFdKHR>(
@@ -791,9 +791,9 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
       return false;
     }
   }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME)) {
     vkGetMemoryFdKHRFn = reinterpret_cast<PFN_vkGetMemoryFdKHR>(
@@ -813,7 +813,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
       return false;
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_FUCHSIA)
   if (gfx::HasExtension(enabled_extensions,
