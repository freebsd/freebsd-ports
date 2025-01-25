--- components/viz/service/display_embedder/software_output_surface.cc.orig	2025-01-15 09:18:26 UTC
+++ components/viz/service/display_embedder/software_output_surface.cc
@@ -113,7 +113,7 @@ void SoftwareOutputSurface::SwapBuffersCallback(base::
   base::TimeTicks now = base::TimeTicks::Now();
   base::TimeDelta interval_to_next_refresh =
       now.SnappedToNextTick(refresh_timebase_, refresh_interval_) - now;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (needs_swap_size_notifications_)
     client_->DidSwapWithSize(pixel_size);
 #endif
@@ -140,7 +140,7 @@ gfx::OverlayTransform SoftwareOutputSurface::GetDispla
   return gfx::OVERLAY_TRANSFORM_NONE;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SoftwareOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {
   needs_swap_size_notifications_ = needs_swap_size_notifications;
