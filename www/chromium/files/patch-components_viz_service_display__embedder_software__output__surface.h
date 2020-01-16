--- components/viz/service/display_embedder/software_output_surface.h.orig	2019-12-17 19:30:42 UTC
+++ components/viz/service/display_embedder/software_output_surface.h
@@ -50,7 +50,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputSurface : publi
       UpdateVSyncParametersCallback callback) override;
   void SetDisplayTransformHint(gfx::OverlayTransform transform) override {}
   gfx::OverlayTransform GetDisplayTransform() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
@@ -70,7 +70,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputSurface : publi
   std::queue<std::vector<ui::LatencyInfo>> stored_latency_info_;
   ui::LatencyTracker latency_tracker_;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   bool needs_swap_size_notifications_ = false;
 #endif
 
