--- components/viz/service/display_embedder/software_output_surface.h.orig	2020-05-13 18:39:42 UTC
+++ components/viz/service/display_embedder/software_output_surface.h
@@ -49,7 +49,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputSurface : publi
       UpdateVSyncParametersCallback callback) override;
   void SetDisplayTransformHint(gfx::OverlayTransform transform) override {}
   gfx::OverlayTransform GetDisplayTransform() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
@@ -72,7 +72,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputSurface : publi
   std::queue<std::vector<ui::LatencyInfo>> stored_latency_info_;
   ui::LatencyTracker latency_tracker_;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   bool needs_swap_size_notifications_ = false;
 #endif
 
