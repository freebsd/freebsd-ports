--- chrome/browser/web_applications/web_app_shortcut.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/web_applications/web_app_shortcut.h
@@ -19,7 +19,7 @@
 #include "ui/gfx/image/image_family.h"
 #include "url/gurl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/web_applications/web_app_shortcut_linux.h"
 #endif  // defined(OS_LINUX)
 
@@ -47,7 +47,7 @@ struct ScopedShortcutOverrideForTesting {
   base::ScopedTempDir startup;
 #elif defined(OS_MAC)
   base::ScopedTempDir chrome_apps_folder;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   base::ScopedTempDir desktop;
 #endif
 };
@@ -89,7 +89,7 @@ struct ShortcutInfo {
   std::set<std::string> file_handler_extensions;
   std::set<std::string> file_handler_mime_types;
   std::set<std::string> protocol_handlers;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::set<DesktopActionInfo> actions;
 #endif  // defined(OS_LINUX)
 
