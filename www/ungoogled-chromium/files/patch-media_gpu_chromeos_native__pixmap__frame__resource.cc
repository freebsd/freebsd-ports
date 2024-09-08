--- media/gpu/chromeos/native_pixmap_frame_resource.cc.orig	2024-08-26 14:40:28 UTC
+++ media/gpu/chromeos/native_pixmap_frame_resource.cc
@@ -176,7 +176,7 @@ scoped_refptr<NativePixmapFrameResource> NativePixmapF
   const bool is_intel_media_compression_enabled =
 #if BUILDFLAG(IS_CHROMEOS)
       base::FeatureList::IsEnabled(features::kEnableIntelMediaCompression);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       false;
 #endif
   CHECK(!is_intel_media_compressed_buffer ||
