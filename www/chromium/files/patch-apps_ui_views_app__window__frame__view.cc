--- apps/ui/views/app_window_frame_view.cc.orig	2019-06-04 18:55:14 UTC
+++ apps/ui/views/app_window_frame_view.cc
@@ -125,7 +125,7 @@ gfx::Rect AppWindowFrameView::GetBoundsForClientView()
 gfx::Rect AppWindowFrameView::GetWindowBoundsForClientBounds(
     const gfx::Rect& client_bounds) const {
   gfx::Rect window_bounds = client_bounds;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Get the difference between the widget's client area bounds and window
   // bounds, and grow |window_bounds| by that amount.
   gfx::Insets native_frame_insets =
