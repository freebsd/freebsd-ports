--- src/brave/chromium_src/chrome/browser/ui/views/frame/browser_frame_view_factory_views.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/chrome/browser/ui/views/frame/browser_frame_view_factory_views.cc
@@ -18,16 +18,16 @@
 #include "chrome/browser/ui/views/frame/browser_frame_view_linux.h"
 #define OpaqueBrowserFrameView BraveOpaqueBrowserFrameView
 
-#if BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "brave/browser/ui/views/frame/brave_browser_frame_view_linux_native.h"
 #define BrowserFrameViewLinuxNative BraveBrowserFrameViewLinuxNative
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 
 #include <chrome/browser/ui/views/frame/browser_frame_view_factory_views.cc>
 
 #undef OpaqueBrowserFrameView
 
-#if BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #undef BrowserFrameViewLinuxNative
 
 // A sanity check for our macro
@@ -39,7 +39,7 @@
                        BrowserView*>>,
     "CreateOpaqueBrowserFrameViewLinux is not returning "
     "BraveOpaqueBrowserFrameView");
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 
 #if BUILDFLAG(IS_WIN)
 #undef BrowserFrameViewWin
