--- components/viz/test/fake_output_surface.cc.orig	2021-04-14 18:41:02 UTC
+++ components/viz/test/fake_output_surface.cc
@@ -118,7 +118,7 @@ gfx::OverlayTransform FakeOutputSurface::GetDisplayTra
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 void FakeOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {}
 #endif
