--- components/viz/test/fake_output_surface.h.orig	2021-04-14 18:41:02 UTC
+++ components/viz/test/fake_output_surface.h
@@ -89,7 +89,7 @@ class FakeOutputSurface : public OutputSurface {
   gfx::OverlayTransform GetDisplayTransform() override;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
