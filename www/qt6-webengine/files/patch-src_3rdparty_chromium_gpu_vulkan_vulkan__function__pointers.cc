--- src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.cc.orig	2022-04-21 18:48:31 UTC
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.cc
@@ -1151,7 +1151,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME)) {
     vkGetImageDrmFormatModifierPropertiesEXT =
