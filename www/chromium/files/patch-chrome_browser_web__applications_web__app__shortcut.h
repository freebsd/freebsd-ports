--- chrome/browser/web_applications/web_app_shortcut.h.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/web_applications/web_app_shortcut.h
@@ -19,9 +19,9 @@
 #include "ui/gfx/image/image_family.h"
 #include "url/gurl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/web_applications/web_app_shortcut_linux.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace base {
 class TaskRunner;
@@ -47,7 +47,7 @@ struct ScopedShortcutOverrideForTesting {
   base::ScopedTempDir startup;
 #elif defined(OS_MAC)
   base::ScopedTempDir chrome_apps_folder;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   base::ScopedTempDir desktop;
 #endif
 };
@@ -89,9 +89,9 @@ struct ShortcutInfo {
   std::set<std::string> file_handler_extensions;
   std::set<std::string> file_handler_mime_types;
   std::set<std::string> protocol_handlers;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::set<DesktopActionInfo> actions;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   // An app is multi-profile if there is a single shortcut and single app shim
   // for all profiles. The app itself has a profile switcher that may be used
