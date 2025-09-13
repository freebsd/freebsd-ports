--- components/viz/service/display_embedder/software_output_surface.h.orig	2025-09-11 13:19:19 UTC
+++ components/viz/service/display_embedder/software_output_surface.h
@@ -40,7 +40,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputSurface : publi
       UpdateVSyncParametersCallback callback) override;
   void SetDisplayTransformHint(gfx::OverlayTransform transform) override {}
   gfx::OverlayTransform GetDisplayTransform() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
@@ -58,7 +58,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputSurface : publi
   base::TimeTicks refresh_timebase_;
   base::TimeDelta refresh_interval_ = BeginFrameArgs::DefaultInterval();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool needs_swap_size_notifications_ = false;
 #endif
 
