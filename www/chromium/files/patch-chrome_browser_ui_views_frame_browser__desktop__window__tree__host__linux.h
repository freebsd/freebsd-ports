--- chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.h
@@ -95,7 +95,7 @@ class BrowserDesktopWindowTreeHostLinux
 // browser_desktop_window_tree_host_lacros.cc.
 #if BUILDFLAG(IS_CHROMEOS_LACROS)
   using DesktopBrowserFrameAuraPlatform = DesktopBrowserFrameLacros;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   using DesktopBrowserFrameAuraPlatform = DesktopBrowserFrameAuraLinux;
 #else
 #error Unknown platform
