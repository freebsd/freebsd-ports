--- chrome/browser/web_applications/web_app_shortcut.cc.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/web_applications/web_app_shortcut.cc
@@ -39,7 +39,7 @@ namespace {
 
 #if defined(OS_MAC)
 const int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredIconSizesForShortcut[] = {16, 32, 48, 128, 256, 512};
@@ -119,7 +119,7 @@ ScopedShortcutOverrideForTesting::~ScopedShortcutOverr
       }
     }
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   directories = {&desktop};
 #endif
   for (base::ScopedTempDir* dir : directories) {
@@ -160,7 +160,7 @@ std::unique_ptr<ScopedShortcutOverrideForTesting> Over
         scoped_override->chrome_apps_folder.CreateUniqueTempDirUnderPath(
             base_path);
     DCHECK(success);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     bool success =
         scoped_override->desktop.CreateUniqueTempDirUnderPath(base_path);
     DCHECK(success);
@@ -178,7 +178,7 @@ std::unique_ptr<ScopedShortcutOverrideForTesting> Over
 #elif defined(OS_MAC)
     bool success = scoped_override->chrome_apps_folder.CreateUniqueTempDir();
     DCHECK(success);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     bool success = scoped_override->desktop.CreateUniqueTempDir();
     DCHECK(success);
 #endif
