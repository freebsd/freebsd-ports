--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2024-12-22 12:24:29 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -214,7 +214,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
