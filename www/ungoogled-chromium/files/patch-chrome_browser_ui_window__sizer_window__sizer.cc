--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -219,7 +219,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
