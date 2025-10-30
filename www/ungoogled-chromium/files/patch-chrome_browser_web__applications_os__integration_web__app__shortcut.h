--- chrome/browser/web_applications/os_integration/web_app_shortcut.h.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.h
@@ -23,7 +23,7 @@
 #include "ui/gfx/image/image_family.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/os_integration/web_app_shortcut_linux.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -78,7 +78,7 @@ struct ShortcutInfo {
   // the installed PWA experience and thus the icons are not designed to be
   // displayed on an OS dock.
   bool is_diy_app = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::set<DesktopActionInfo> actions;
 #endif  // BUILDFLAG(IS_LINUX)
 
