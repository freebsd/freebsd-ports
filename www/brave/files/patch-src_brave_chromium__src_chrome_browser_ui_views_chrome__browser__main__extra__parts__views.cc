--- src/brave/chromium_src/chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc
@@ -5,13 +5,13 @@
 
 #include "build/build_config.h"  // For OS_LINUX
 
-#if BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "brave/browser/ui/views/brave_views_delegate_linux.h"
 #undef ChromeViewsDelegate
 #define ChromeViewsDelegate BraveViewsDelegateLinux
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 
 #include <chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc>
-#if BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #undef ChromeViewsDelegate
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
