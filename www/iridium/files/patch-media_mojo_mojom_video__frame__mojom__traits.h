--- media/mojo/mojom/video_frame_mojom_traits.h.orig	2026-08-13 16:48:13 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.h
@@ -18,7 +18,7 @@
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 template <>
 struct StructTraits<media::mojom::ColorPlaneLayoutDataView,
                     media::ColorPlaneLayout> {
