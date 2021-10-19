--- chrome/browser/web_applications/components/web_app_shortcut.h.orig	2021-09-24 18:36:37 UTC
+++ chrome/browser/web_applications/components/web_app_shortcut.h
@@ -39,7 +39,7 @@ struct ShortcutOverrideForTesting {
   base::FilePath startup;
 #elif defined(OS_MAC)
   base::FilePath chrome_apps_folder;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   base::FilePath desktop;
 #else
 #endif
