--- media/gpu/chromeos/libyuv_image_processor_backend.cc.orig	2024-02-03 15:42:55 UTC
+++ media/gpu/chromeos/libyuv_image_processor_backend.cc
@@ -47,7 +47,7 @@ static constexpr struct {
 #define CONV(in, out, trans, result) \
   {Fourcc::in, Fourcc::out, Transform::trans, SupportResult::result}
     // Conversion.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     CONV(NV12, AR24, kConversion, Supported),
 #endif
     CONV(NV12, NV12, kConversion, Supported),
@@ -430,7 +430,7 @@ int LibYUVImageProcessorBackend::DoConversion(const Vi
           fr->GetWritableVisibleData(VideoFrame::kUVPlane)), \
       fr->stride(VideoFrame::kUVPlane)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define ARGB_DATA(fr)                                 \
   fr->GetWritableVisibleData(VideoFrame::kARGBPlane), \
       fr->stride(VideoFrame::kARGBPlane)
@@ -573,7 +573,7 @@ int LibYUVImageProcessorBackend::DoConversion(const Vi
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (output->format() == PIXEL_FORMAT_ARGB) {
     if (input_config_.fourcc == Fourcc(Fourcc::NV12)) {
       return LIBYUV_FUNC(NV12ToARGB, Y_UV_DATA(input),
