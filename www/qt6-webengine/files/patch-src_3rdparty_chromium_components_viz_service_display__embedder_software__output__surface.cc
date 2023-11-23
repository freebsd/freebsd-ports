--- src/3rdparty/chromium/components/viz/service/display_embedder/software_output_surface.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/components/viz/service/display_embedder/software_output_surface.cc
@@ -98,7 +98,7 @@ void SoftwareOutputSurface::SwapBuffersCallback(base::
       now.SnappedToNextTick(refresh_timebase_, refresh_interval_) - now;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   if (needs_swap_size_notifications_)
     client_->DidSwapWithSize(pixel_size);
 #endif
@@ -125,7 +125,7 @@ gfx::OverlayTransform SoftwareOutputSurface::GetDispla
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 void SoftwareOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {
   needs_swap_size_notifications_ = needs_swap_size_notifications;
