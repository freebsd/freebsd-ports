--- ui/ozone/platform/wayland/host/wayland_toplevel_window.cc.orig	2025-01-15 09:18:26 UTC
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.cc
@@ -616,7 +616,7 @@ void WaylandToplevelWindow::HandleToplevelConfigureWit
   bool prev_suspended = is_suspended_;
   is_suspended_ = window_states.is_suspended;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The tiled state affects the window geometry, so apply it here.
   if (window_states.tiled_edges != tiled_state_) {
     // This configure changes the decoration insets.  We should adjust the
