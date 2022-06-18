--- components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2022-06-17 14:20:10 UTC
+++ components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1145,7 +1145,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::GetGrBackendFor
                                           ->GetDeviceQueue()
                                           ->GetVulkanPhysicalDevice(),
                                       VK_IMAGE_TILING_OPTIMAL, ycbcr_info);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormat::MakeVk(gr_ycbcr_info,
