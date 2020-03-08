--- components/viz/service/display_embedder/software_output_surface.cc.orig	2020-03-03 18:53:54 UTC
+++ components/viz/service/display_embedder/software_output_surface.cc
@@ -118,7 +118,7 @@ void SoftwareOutputSurface::SwapBuffersCallback(base::
   base::TimeTicks now = base::TimeTicks::Now();
   base::TimeDelta interval_to_next_refresh =
       now.SnappedToNextTick(refresh_timebase_, refresh_interval_) - now;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (needs_swap_size_notifications_)
     client_->DidSwapWithSize(pixel_size);
 #endif
@@ -147,7 +147,7 @@ gfx::OverlayTransform SoftwareOutputSurface::GetDispla
   return gfx::OVERLAY_TRANSFORM_NONE;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void SoftwareOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {
   needs_swap_size_notifications_ = needs_swap_size_notifications;
