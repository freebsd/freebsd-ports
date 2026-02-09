--- media/gpu/chromeos/libyuv_image_processor_backend.cc.orig	2026-02-15 10:01:45 UTC
+++ media/gpu/chromeos/libyuv_image_processor_backend.cc
@@ -52,7 +52,7 @@ static constexpr struct {
 #define CONV(in, out, trans, result) \
   {Fourcc::in, Fourcc::out, Transform::trans, SupportResult::result}
     // Conversion.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     CONV(NV12, AR24, kConversion, Supported),
 #endif
     CONV(NV12, NV12, kConversion, Supported),
@@ -411,7 +411,7 @@ int LibYUVImageProcessorBackend::DoConversion(const Fr
           fr->GetWritableVisibleData(VideoFrame::Plane::kUV)), \
       fr->stride(VideoFrame::Plane::kUV)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define ARGB_DATA(fr)                                   \
   fr->GetWritableVisibleData(VideoFrame::Plane::kARGB), \
       fr->stride(VideoFrame::Plane::kARGB)
@@ -573,7 +573,7 @@ int LibYUVImageProcessorBackend::DoConversion(const Fr
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (output->format() == PIXEL_FORMAT_ARGB) {
     if (input_config_.fourcc == Fourcc(Fourcc::NV12)) {
       return LIBYUV_FUNC(NV12ToARGB, Y_UV_DATA(input),
