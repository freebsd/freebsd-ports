--- apps/ui/views/app_window_frame_view.cc.orig	2025-12-10 15:04:57 UTC
+++ apps/ui/views/app_window_frame_view.cc
@@ -146,7 +146,7 @@ gfx::Rect AppWindowFrameView::GetBoundsForClientView()
 gfx::Rect AppWindowFrameView::GetWindowBoundsForClientBounds(
     const gfx::Rect& client_bounds) const {
   gfx::Rect window_bounds = client_bounds;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Get the difference between the widget's client area bounds and window
   // bounds, and grow |window_bounds| by that amount.
   gfx::Insets native_frame_insets =
