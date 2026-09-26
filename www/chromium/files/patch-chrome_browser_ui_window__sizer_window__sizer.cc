--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -225,7 +225,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
