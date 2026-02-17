--- media/mojo/mojom/video_frame_mojom_traits.h.orig	2026-02-15 10:01:45 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.h
@@ -20,7 +20,7 @@
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 template <>
 struct StructTraits<media::mojom::ColorPlaneLayoutDataView,
                     media::ColorPlaneLayout> {
