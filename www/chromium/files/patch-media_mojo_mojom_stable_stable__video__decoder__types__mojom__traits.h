--- media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.h.orig	2022-06-17 14:20:10 UTC
+++ media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.h
@@ -625,7 +625,7 @@ struct StructTraits<media::stable::mojom::NativeGpuMem
   static const gfx::GpuMemoryBufferId& id(
       const gfx::GpuMemoryBufferHandle& input);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static gfx::NativePixmapHandle platform_handle(
       gfx::GpuMemoryBufferHandle& input);
 #else
