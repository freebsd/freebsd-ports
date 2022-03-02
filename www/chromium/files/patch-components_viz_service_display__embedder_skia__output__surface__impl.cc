--- components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2022-02-28 16:54:41 UTC
+++ components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1162,7 +1162,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::GetGrBackendFor
                                           ->GetDeviceQueue()
                                           ->GetVulkanPhysicalDevice(),
                                       VK_IMAGE_TILING_OPTIMAL, ycbcr_info);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormat::MakeVk(gr_ycbcr_info,
