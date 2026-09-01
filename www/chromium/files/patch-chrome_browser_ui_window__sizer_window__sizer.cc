--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -224,7 +224,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
