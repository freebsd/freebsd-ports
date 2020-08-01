--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc.orig	2020-07-07 21:58:15 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc
@@ -50,7 +50,7 @@ RootCompositorFrameSinkImpl::Create(
   output_surface->SetNeedsSwapSizeNotifications(
       params->send_swap_size_notifications);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // For X11, we need notify client about swap completion after resizing, so the
   // client can use it for synchronize with X11 WM.
   output_surface->SetNeedsSwapSizeNotifications(true);
@@ -448,7 +448,7 @@ void RootCompositorFrameSinkImpl::DisplayDidCompleteSw
 #if defined(OS_ANDROID)
   if (display_client_)
     display_client_->DidCompleteSwapWithSize(pixel_size);
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (display_client_ && pixel_size != last_swap_pixel_size_) {
     last_swap_pixel_size_ = pixel_size;
     display_client_->DidCompleteSwapWithNewSize(last_swap_pixel_size_);
