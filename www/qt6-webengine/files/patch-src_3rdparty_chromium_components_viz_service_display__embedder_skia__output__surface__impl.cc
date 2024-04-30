--- src/3rdparty/chromium/components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2023-10-11 18:22:24 UTC
+++ src/3rdparty/chromium/components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1485,7 +1485,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::GetGrBackendFor
                                           ->GetDeviceQueue()
                                           ->GetVulkanPhysicalDevice(),
                                       VK_IMAGE_TILING_OPTIMAL, ycbcr_info);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormats::MakeVk(gr_ycbcr_info,
