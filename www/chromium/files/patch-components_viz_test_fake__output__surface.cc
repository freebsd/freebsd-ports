--- components/viz/test/fake_output_surface.cc.orig	2020-11-13 06:36:42 UTC
+++ components/viz/test/fake_output_surface.cc
@@ -115,7 +115,7 @@ gfx::OverlayTransform FakeOutputSurface::GetDisplayTra
                                          : gfx::OVERLAY_TRANSFORM_NONE;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void FakeOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {}
 #endif
