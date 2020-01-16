--- content/browser/compositor/software_browser_compositor_output_surface.cc.orig	2019-12-17 19:33:09 UTC
+++ content/browser/compositor/software_browser_compositor_output_surface.cc
@@ -89,7 +89,7 @@ void SoftwareBrowserCompositorOutputSurface::SwapBuffe
     const gfx::Size& pixel_size) {
   latency_tracker_.OnGpuSwapBuffersCompleted(latency_info);
   client_->DidReceiveSwapBuffersAck({swap_time, swap_time});
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (needs_swap_size_notifications_)
     client_->DidSwapWithSize(pixel_size);
 #endif
@@ -129,7 +129,7 @@ unsigned SoftwareBrowserCompositorOutputSurface::Updat
   return 0;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void SoftwareBrowserCompositorOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {
   needs_swap_size_notifications_ = needs_swap_size_notifications;
