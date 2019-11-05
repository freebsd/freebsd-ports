--- ui/platform_window/platform_window_delegate.h.orig	2019-10-30 16:37:03 UTC
+++ ui/platform_window/platform_window_delegate.h
@@ -9,7 +9,7 @@
 
 // By default, PlatformWindowDelegateBase is used. However, different platforms
 // should specify what delegate they would like to use if needed.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/platform_window/platform_window_delegate_linux.h"
 #else
 #include "ui/platform_window/platform_window_delegate_base.h"
@@ -17,7 +17,7 @@
 
 namespace ui {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 using PlatformWindowDelegate = PlatformWindowDelegateLinux;
 #else
 using PlatformWindowDelegate = PlatformWindowDelegateBase;
