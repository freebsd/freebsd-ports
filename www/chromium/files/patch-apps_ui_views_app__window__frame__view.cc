--- apps/ui/views/app_window_frame_view.cc.orig	2021-01-18 21:28:44 UTC
+++ apps/ui/views/app_window_frame_view.cc
@@ -139,7 +139,7 @@ gfx::Rect AppWindowFrameView::GetWindowBoundsForClient
   gfx::Rect window_bounds = client_bounds;
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || defined(OS_BSD) || BUILDFLAG(IS_CHROMEOS_LACROS)
   // Get the difference between the widget's client area bounds and window
   // bounds, and grow |window_bounds| by that amount.
   gfx::Insets native_frame_insets =
