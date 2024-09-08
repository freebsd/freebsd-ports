--- components/viz/service/display_embedder/software_output_surface.cc.orig	2024-08-27 06:28:16 UTC
+++ components/viz/service/display_embedder/software_output_surface.cc
@@ -119,7 +119,7 @@ void SoftwareOutputSurface::SwapBuffersCallback(base::
       now.SnappedToNextTick(refresh_timebase_, refresh_interval_) - now;
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   if (needs_swap_size_notifications_)
     client_->DidSwapWithSize(pixel_size);
 #endif
@@ -148,7 +148,7 @@ gfx::OverlayTransform SoftwareOutputSurface::GetDispla
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 void SoftwareOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {
   needs_swap_size_notifications_ = needs_swap_size_notifications;
