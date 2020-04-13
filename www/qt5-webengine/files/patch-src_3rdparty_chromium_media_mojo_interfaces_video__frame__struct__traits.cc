--- src/3rdparty/chromium/media/mojo/interfaces/video_frame_struct_traits.cc.orig	2020-04-05 20:03:42 UTC
+++ src/3rdparty/chromium/media/mojo/interfaces/video_frame_struct_traits.cc
@@ -49,7 +49,7 @@ media::mojom::VideoFrameDataPtr MakeVideoFrameData(
             mojo_frame->PlaneOffset(media::VideoFrame::kVPlane)));
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (input->storage_type() == media::VideoFrame::STORAGE_DMABUFS) {
     std::vector<mojo::ScopedHandle> dmabuf_fds;
 
@@ -142,7 +142,7 @@ bool StructTraits<media::mojom::VideoFrameDataView,
         shared_buffer_data.u_offset(), shared_buffer_data.v_offset(),
         shared_buffer_data.y_stride(), shared_buffer_data.u_stride(),
         shared_buffer_data.v_stride(), timestamp);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (data.is_dmabuf_data()) {
     media::mojom::DmabufVideoFrameDataDataView dmabuf_data;
     data.GetDmabufDataDataView(&dmabuf_data);
