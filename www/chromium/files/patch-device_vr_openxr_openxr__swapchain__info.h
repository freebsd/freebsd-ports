--- device/vr/openxr/openxr_swapchain_info.h.orig	2026-09-25 15:26:43 UTC
+++ device/vr/openxr/openxr_swapchain_info.h
@@ -19,7 +19,7 @@
 #include "ui/gl/scoped_egl_image.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <vulkan/vulkan_core.h>
 #endif
 
@@ -32,7 +32,7 @@ struct OpenXrSwapchainInfo {
   explicit OpenXrSwapchainInfo(ID3D11Texture2D*);
 #elif BUILDFLAG(IS_ANDROID)
   explicit OpenXrSwapchainInfo(uint32_t texture);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   explicit OpenXrSwapchainInfo(VkImage vk_image);
 #endif
   OpenXrSwapchainInfo();
@@ -55,7 +55,7 @@ struct OpenXrSwapchainInfo {
   // texture prior to submission.
   Microsoft::WRL::ComPtr<ID3D11Texture2D> d3d11_shared_texture = nullptr;
   Microsoft::WRL::ComPtr<ID3D11Fence> d3d11_fence;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The Vulkan image handle from the OpenXR swapchain.
   VkImage vk_image = VK_NULL_HANDLE;
 #elif BUILDFLAG(IS_ANDROID)
