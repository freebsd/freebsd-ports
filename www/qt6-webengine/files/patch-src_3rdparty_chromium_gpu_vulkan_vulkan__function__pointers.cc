--- src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.cc.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.cc
@@ -1161,7 +1161,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME)) {
     vkGetImageDrmFormatModifierPropertiesEXT =
@@ -1350,7 +1350,7 @@ void VulkanFunctionPointers::ResetForTesting() {
   vkGetSwapchainImagesKHR = nullptr;
   vkQueuePresentKHR = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   vkGetImageDrmFormatModifierPropertiesEXT = nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
