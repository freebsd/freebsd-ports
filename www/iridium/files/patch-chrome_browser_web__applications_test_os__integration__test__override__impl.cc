--- chrome/browser/web_applications/test/os_integration_test_override_impl.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/web_applications/test/os_integration_test_override_impl.cc
@@ -127,7 +127,7 @@ std::vector<std::wstring> GetFileExtensionsForProgId(
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Performs a blocking read of app icons from the disk.
 SkColor IconManagerReadIconTopLeftColorForSize(WebAppIconManager& icon_manager,
                                                const webapps::AppId& app_id,
@@ -224,7 +224,7 @@ bool OsIntegrationTestOverrideImpl::SimulateDeleteShor
       GetShortcutPath(profile, chrome_apps_folder(), app_id, app_name);
   CHECK(base::PathExists(app_folder_shortcut_path));
   return base::DeletePathRecursively(app_folder_shortcut_path);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath desktop_shortcut_path =
       GetShortcutPath(profile, desktop(), app_id, app_name);
   LOG(INFO) << desktop_shortcut_path;
@@ -264,7 +264,7 @@ bool OsIntegrationTestOverrideImpl::DeleteApplicationM
 }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OsIntegrationTestOverrideImpl::DeleteDesktopDirOnLinux() {
   if (desktop_.IsValid()) {
     return desktop_.Delete();
@@ -278,7 +278,7 @@ bool OsIntegrationTestOverrideImpl::IsRunOnOsLoginEnab
     Profile* profile,
     const webapps::AppId& app_id,
     const std::string& app_name) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string shortcut_filename =
       "chrome-" + app_id + "-" + profile->GetBaseName().value() + ".desktop";
   return base::PathExists(startup().Append(shortcut_filename));
@@ -334,7 +334,7 @@ bool OsIntegrationTestOverrideImpl::IsFileExtensionHan
   is_file_handled =
       shell_integration::CanApplicationHandleURL(app_path, test_file_url);
   base::DeleteFile(test_file_path);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath user_applications_dir =
       applications_dir().Append("applications");
   bool database_update_called = false;
@@ -378,7 +378,7 @@ OsIntegrationTestOverrideImpl::GetShortcutIconTopLeftC
     return absl::nullopt;
   }
   return GetIconTopLeftColorFromShortcutFile(shortcut_path);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   WebAppProvider* provider = WebAppProvider::GetForLocalAppsUnchecked(profile);
   if (!provider) {
     return absl::nullopt;
@@ -428,7 +428,7 @@ base::FilePath OsIntegrationTestOverrideImpl::GetShort
       app_installed_profiles.end()) {
     return shortcut_path;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string shortcut_filename =
       "chrome-" + app_id + "-" + profile->GetBaseName().value() + ".desktop";
   base::FilePath shortcut_path = shortcut_dir.Append(shortcut_filename);
@@ -454,7 +454,7 @@ bool OsIntegrationTestOverrideImpl::IsShortcutCreated(
   base::FilePath app_shortcut_path =
       GetShortcutPath(profile, chrome_apps_folder(), app_id, app_name);
   return base::PathExists(app_shortcut_path);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath desktop_shortcut_path =
       GetShortcutPath(profile, desktop(), app_id, app_name);
   return base::PathExists(desktop_shortcut_path);
@@ -643,7 +643,7 @@ void OsIntegrationTestOverrideImpl::EnableOrDisablePat
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::FilePath& OsIntegrationTestOverrideImpl::desktop() {
   return desktop_.GetPath();
 }
@@ -678,7 +678,7 @@ OsIntegrationTestOverrideImpl::OsIntegrationTestOverri
 #elif BUILDFLAG(IS_MAC)
     bool success = chrome_apps_folder_.CreateUniqueTempDirUnderPath(base_path);
     CHECK(success);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool success = desktop_.CreateUniqueTempDirUnderPath(base_path);
     CHECK(success);
     success = startup_.CreateUniqueTempDirUnderPath(base_path);
@@ -699,7 +699,7 @@ OsIntegrationTestOverrideImpl::OsIntegrationTestOverri
 #elif BUILDFLAG(IS_MAC)
     bool success = chrome_apps_folder_.CreateUniqueTempDir();
     CHECK(success);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool success = desktop_.CreateUniqueTempDir();
     CHECK(success);
     success = startup_.CreateUniqueTempDir();
@@ -709,7 +709,7 @@ OsIntegrationTestOverrideImpl::OsIntegrationTestOverri
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto callback = base::BindRepeating([](base::FilePath filename_in,
                                          std::string xdg_command,
                                          std::string file_contents) {
@@ -756,7 +756,7 @@ OsIntegrationTestOverrideImpl::~OsIntegrationTestOverr
       }
     }
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reset the file handling callback.
   SetUpdateMimeInfoDatabaseOnLinuxCallbackForTesting(
       UpdateMimeInfoDatabaseOnLinuxCallback());
