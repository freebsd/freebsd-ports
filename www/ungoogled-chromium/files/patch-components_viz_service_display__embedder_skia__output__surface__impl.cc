--- components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2026-01-16 13:40:34 UTC
+++ components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1562,7 +1562,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::GetGrBackendFor
                                         VK_IMAGE_TILING_OPTIMAL, vk_format,
                                         si_format, image_context->color_space(),
                                         image_context->ycbcr_info());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormats::MakeVk(gr_ycbcr_info,
