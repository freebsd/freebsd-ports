--- media/mojo/mojom/video_frame_mojom_traits.cc.orig	2020-02-24 18:39:18 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.cc
@@ -20,9 +20,9 @@
 #include "ui/gfx/mojom/buffer_types_mojom_traits.h"
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/posix/eintr_wrapper.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace mojo {
 
@@ -60,7 +60,7 @@ media::mojom::VideoFrameDataPtr MakeVideoFrameData(
             mojo_frame->PlaneOffset(media::VideoFrame::kVPlane)));
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (input->storage_type() == media::VideoFrame::STORAGE_DMABUFS) {
     std::vector<mojo::ScopedHandle> dmabuf_fds;
 
@@ -161,7 +161,7 @@ bool StructTraits<media::mojom::VideoFrameDataView,
         shared_buffer_data.u_offset(), shared_buffer_data.v_offset(),
         shared_buffer_data.y_stride(), shared_buffer_data.u_stride(),
         shared_buffer_data.v_stride(), timestamp);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (data.is_dmabuf_data()) {
     media::mojom::DmabufVideoFrameDataDataView dmabuf_data;
     data.GetDmabufDataDataView(&dmabuf_data);
