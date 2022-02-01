--- components/viz/host/renderer_settings_creation.cc.orig	2021-12-14 11:45:04 UTC
+++ components/viz/host/renderer_settings_creation.cc
@@ -56,7 +56,7 @@ RendererSettings CreateRendererSettings() {
   renderer_settings.partial_swap_enabled =
       !command_line->HasSwitch(switches::kUIDisablePartialSwap);
 
-#if defined(OS_APPLE) || defined(OS_LINUX)
+#if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD)
   // Simple frame rate throttling only works on macOS and Linux
   renderer_settings.apply_simple_frame_rate_throttling =
       features::IsSimpleFrameRateThrottlingEnabled();
