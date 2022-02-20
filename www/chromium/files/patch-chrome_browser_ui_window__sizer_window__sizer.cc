--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -166,7 +166,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) || defined(OS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
