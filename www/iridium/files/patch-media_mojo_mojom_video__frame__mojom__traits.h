--- media/mojo/mojom/video_frame_mojom_traits.h.orig	2025-12-10 15:04:57 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.h
@@ -21,7 +21,7 @@
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 template <>
 struct StructTraits<media::mojom::ColorPlaneLayoutDataView,
                     media::ColorPlaneLayout> {
