--- media/gpu/vaapi/vaapi_dmabuf_video_frame_mapper.cc.orig	2019-07-24 18:58:30 UTC
+++ media/gpu/vaapi/vaapi_dmabuf_video_frame_mapper.cc
@@ -15,7 +15,7 @@
 #include "media/gpu/vaapi/vaapi_wrapper.h"
 #include "media/video/picture.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "media/gpu/linux/platform_video_frame_utils.h"
 #endif
 
@@ -137,7 +137,7 @@ scoped_refptr<VideoFrame> VaapiDmaBufVideoFrameMapper:
   }
 
   gfx::GpuMemoryBufferHandle gmb_handle;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   gmb_handle = CreateGpuMemoryBufferHandle(video_frame.get());
 #endif
   if (gmb_handle.is_null()) {
