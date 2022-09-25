--- chrome/browser/web_applications/os_integration/web_app_shortcut.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.cc
@@ -45,7 +45,7 @@ namespace {
 
 #if BUILDFLAG(IS_MAC)
 const int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredIconSizesForShortcut[] = {16, 32, 48, 128, 256, 512};
@@ -130,7 +130,7 @@ std::string GetAllFilesInDir(const base::FilePath& fil
 }  // namespace
 
 ScopedShortcutOverrideForTesting::ScopedShortcutOverrideForTesting() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto callback = base::BindRepeating(
       [](ScopedShortcutOverrideForTesting* scoped_override,
          base::FilePath filename, std::string xdg_command,
@@ -163,7 +163,7 @@ ScopedShortcutOverrideForTesting::~ScopedShortcutOverr
       }
     }
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reset the file handling callback.
   SetUpdateMimeInfoDatabaseOnLinuxCallbackForTesting(
       UpdateMimeInfoDatabaseOnLinuxCallback());
@@ -210,7 +210,7 @@ std::unique_ptr<ScopedShortcutOverrideForTesting> Over
         scoped_override->chrome_apps_folder.CreateUniqueTempDirUnderPath(
             base_path);
     DCHECK(success);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool success =
         scoped_override->desktop.CreateUniqueTempDirUnderPath(base_path);
     DCHECK(success);
@@ -230,7 +230,7 @@ std::unique_ptr<ScopedShortcutOverrideForTesting> Over
 #elif BUILDFLAG(IS_MAC)
     bool success = scoped_override->chrome_apps_folder.CreateUniqueTempDir();
     DCHECK(success);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool success = scoped_override->desktop.CreateUniqueTempDir();
     DCHECK(success);
     success = scoped_override->startup.CreateUniqueTempDir();
