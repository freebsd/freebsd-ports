--- media/gpu/video_frame_mapper_factory.cc.orig	2019-06-04 18:55:25 UTC
+++ media/gpu/video_frame_mapper_factory.cc
@@ -7,36 +7,36 @@
 #include "build/build_config.h"
 #include "media/gpu/buildflags.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "media/gpu/linux/generic_dmabuf_video_frame_mapper.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
-#if BUILDFLAG(USE_VAAPI) && defined(OS_LINUX)
+#if BUILDFLAG(USE_VAAPI) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "media/gpu/vaapi/vaapi_dmabuf_video_frame_mapper.h"
-#endif  // BUILDFLAG(USE_VAAPI) && defined(OS_LINUX)
+#endif  // BUILDFLAG(USE_VAAPI) && (defined(OS_LINUX) || defined(OS_BSD))
 
 namespace media {
 
 // static
 std::unique_ptr<VideoFrameMapper> VideoFrameMapperFactory::CreateMapper() {
-#if BUILDFLAG(USE_VAAPI) && defined(OS_LINUX)
+#if BUILDFLAG(USE_VAAPI) && (defined(OS_LINUX) || defined(OS_BSD))
   return CreateMapper(false);
 #else
   return CreateMapper(true);
-#endif  // BUILDFLAG(USE_VAAPI) && defined(OS_LINUX)
+#endif  // BUILDFLAG(USE_VAAPI) && (defined(OS_LINUX) || defined(OS_BSD))
 }
 
 // static
 std::unique_ptr<VideoFrameMapper> VideoFrameMapperFactory::CreateMapper(
     bool linear_buffer_mapper) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (linear_buffer_mapper)
     return std::make_unique<GenericDmaBufVideoFrameMapper>();
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
-#if BUILDFLAG(USE_VAAPI) && defined(OS_LINUX)
+#if BUILDFLAG(USE_VAAPI) && (defined(OS_LINUX) || defined(OS_BSD))
   return VaapiDmaBufVideoFrameMapper::Create();
-#endif  // BUILDFLAG(USE_VAAPI) && defined(OS_LINUX)
+#endif  // BUILDFLAG(USE_VAAPI) && (defined(OS_LINUX) || defined(OS_BSD))
 
   return nullptr;
 }
