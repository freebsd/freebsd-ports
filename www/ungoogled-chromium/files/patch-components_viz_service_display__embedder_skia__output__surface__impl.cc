--- components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2022-12-02 17:56:32 UTC
+++ components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1161,7 +1161,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::GetGrBackendFor
                                           ->GetDeviceQueue()
                                           ->GetVulkanPhysicalDevice(),
                                       VK_IMAGE_TILING_OPTIMAL, ycbcr_info);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormat::MakeVk(gr_ycbcr_info,
@@ -1180,7 +1180,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::GetGrBackendFor
     return GrBackendFormat::MakeMtl(ToMTLPixelFormat(resource_format));
 #endif
   } else {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Skip the check as ycbcr info is always set by `VaapiVideoDecoder` on
     // Linux.
     DCHECK(!ycbcr_info);
