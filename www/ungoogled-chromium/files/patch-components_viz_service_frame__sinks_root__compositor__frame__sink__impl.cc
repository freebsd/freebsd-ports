--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc.orig	2024-03-22 14:16:19 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc
@@ -112,7 +112,7 @@ RootCompositorFrameSinkImpl::Create(
   output_surface->SetNeedsSwapSizeNotifications(
       params->send_swap_size_notifications);
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   // For X11, we need notify client about swap completion after resizing, so the
   // client can use it for synchronize with X11 WM.
   output_surface->SetNeedsSwapSizeNotifications(true);
@@ -712,7 +712,7 @@ void RootCompositorFrameSinkImpl::DisplayDidCompleteSw
 #if BUILDFLAG(IS_ANDROID)
   if (display_client_ && enable_swap_competion_callback_)
     display_client_->DidCompleteSwapWithSize(pixel_size);
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   if (display_client_ && pixel_size != last_swap_pixel_size_) {
     last_swap_pixel_size_ = pixel_size;
     display_client_->DidCompleteSwapWithNewSize(last_swap_pixel_size_);
