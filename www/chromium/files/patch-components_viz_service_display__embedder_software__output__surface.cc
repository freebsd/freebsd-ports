--- components/viz/service/display_embedder/software_output_surface.cc.orig	2021-04-14 18:41:02 UTC
+++ components/viz/service/display_embedder/software_output_surface.cc
@@ -115,7 +115,7 @@ void SoftwareOutputSurface::SwapBuffersCallback(base::
       now.SnappedToNextTick(refresh_timebase_, refresh_interval_) - now;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   if (needs_swap_size_notifications_)
     client_->DidSwapWithSize(pixel_size);
 #endif
@@ -146,7 +146,7 @@ gfx::OverlayTransform SoftwareOutputSurface::GetDispla
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 void SoftwareOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {
   needs_swap_size_notifications_ = needs_swap_size_notifications;
