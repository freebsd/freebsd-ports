--- components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2023-01-17 19:19:00 UTC
+++ components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1174,7 +1174,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::GetGrBackendFor
                                           ->GetDeviceQueue()
                                           ->GetVulkanPhysicalDevice(),
                                       VK_IMAGE_TILING_OPTIMAL, ycbcr_info);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormat::MakeVk(gr_ycbcr_info,
@@ -1193,7 +1193,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::GetGrBackendFor
     return GrBackendFormat::MakeMtl(ToMTLPixelFormat(resource_format));
 #endif
   } else {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Skip the check as ycbcr info is always set by `VaapiVideoDecoder` on
     // Linux.
     DCHECK(!ycbcr_info);
