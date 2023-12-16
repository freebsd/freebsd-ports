--- src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.h.orig	2022-04-21 18:48:31 UTC
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.h
@@ -305,7 +305,7 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFunctionPointers
   VulkanFunction<PFN_vkGetSwapchainImagesKHR> vkGetSwapchainImagesKHR;
   VulkanFunction<PFN_vkQueuePresentKHR> vkQueuePresentKHR;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   VulkanFunction<PFN_vkGetImageDrmFormatModifierPropertiesEXT>
       vkGetImageDrmFormatModifierPropertiesEXT;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -1212,7 +1212,7 @@ ALWAYS_INLINE VkResult vkQueuePresentKHR(VkQueue queue
                                                              pPresentInfo);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 ALWAYS_INLINE VkResult vkGetImageDrmFormatModifierPropertiesEXT(
     VkDevice device,
     VkImage image,
@@ -1222,4 +1222,4 @@ ALWAYS_INLINE VkResult vkGetImageDrmFormatModifierProp
 }
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
\ No newline at end of file
+#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
