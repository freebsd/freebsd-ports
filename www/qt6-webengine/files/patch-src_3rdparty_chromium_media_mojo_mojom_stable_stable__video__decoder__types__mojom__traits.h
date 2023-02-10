--- src/3rdparty/chromium/media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.h
@@ -620,7 +620,7 @@ struct StructTraits<media::stable::mojom::NativeGpuMem
   static const gfx::GpuMemoryBufferId& id(
       const gfx::GpuMemoryBufferHandle& input);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static gfx::NativePixmapHandle platform_handle(
       gfx::GpuMemoryBufferHandle& input);
 #else
