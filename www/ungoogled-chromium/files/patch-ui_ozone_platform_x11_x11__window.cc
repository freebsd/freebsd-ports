--- ui/ozone/platform/x11/x11_window.cc.orig	2025-10-21 16:57:35 UTC
+++ ui/ozone/platform/x11/x11_window.cc
@@ -1503,7 +1503,7 @@ void X11Window::OnXWindowStateChanged() {
   WindowTiledEdges tiled_state = GetTiledState();
   if (tiled_state != tiled_state_) {
     tiled_state_ = tiled_state;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     platform_window_delegate_->OnWindowTiledStateChanged(tiled_state);
     UpdateDecorationInsets();
 #endif
