--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2025-05-07 06:48:23 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -220,7 +220,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
