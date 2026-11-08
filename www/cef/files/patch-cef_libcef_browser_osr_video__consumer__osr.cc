--- cef/libcef/browser/osr/video_consumer_osr.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/osr/video_consumer_osr.cc
@@ -183,7 +183,7 @@ void CefVideoConsumerOSR::OnFrameCapture
     paint_info.shared_texture_io_surface = gmb_handle.io_surface().get();
     paint_info.format = pixel_format;
     view_->OnAcceleratedPaint(damage_rect, info->coded_size, paint_info);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto& gmb_handle = data->get_gpu_memory_buffer_handle();
     auto& native_pixmap = gmb_handle.native_pixmap_handle();
     CHECK(native_pixmap.planes.size() <= kAcceleratedPaintMaxPlanes);
