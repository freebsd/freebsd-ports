--- chrome/browser/web_applications/test/os_integration_test_override_impl.cc.orig	2024-10-27 06:40:35 UTC
+++ chrome/browser/web_applications/test/os_integration_test_override_impl.cc
@@ -45,7 +45,7 @@
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "third_party/skia/include/core/SkColor.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -130,7 +130,7 @@ std::vector<std::wstring> GetFileExtensionsForProgId(
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Performs a blocking read of app icons from the disk.
 SkColor IconManagerReadIconTopLeftColorForSize(WebAppIconManager& icon_manager,
                                                const webapps::AppId& app_id,
@@ -265,7 +265,7 @@ bool OsIntegrationTestOverrideImpl::SimulateDeleteShor
       GetShortcutPath(profile, chrome_apps_folder(), app_id, app_name);
   CHECK(base::PathExists(app_folder_shortcut_path));
   return base::DeletePathRecursively(app_folder_shortcut_path);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath desktop_shortcut_path =
       GetShortcutPath(profile, desktop(), app_id, app_name);
   LOG(INFO) << desktop_shortcut_path;
@@ -313,7 +313,7 @@ bool OsIntegrationTestOverrideImpl::DeleteApplicationM
 }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OsIntegrationTestOverrideImpl::DeleteDesktopDirOnLinux() {
   if (desktop_.IsValid()) {
     return desktop_.Delete();
@@ -327,7 +327,7 @@ bool OsIntegrationTestOverrideImpl::IsRunOnOsLoginEnab
     Profile* profile,
     const webapps::AppId& app_id,
     const std::string& app_name) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string shortcut_filename =
       "chrome-" + app_id + "-" + profile->GetBaseName().value() + ".desktop";
   return base::PathExists(startup().Append(shortcut_filename));
@@ -383,7 +383,7 @@ bool OsIntegrationTestOverrideImpl::IsFileExtensionHan
   is_file_handled =
       shell_integration::CanApplicationHandleURL(app_path, test_file_url);
   base::DeleteFile(test_file_path);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath user_applications_dir = applications();
   bool database_update_called = false;
   for (const LinuxFileRegistration& command : linux_file_registration_) {
@@ -426,7 +426,7 @@ OsIntegrationTestOverrideImpl::GetShortcutIconTopLeftC
     return std::nullopt;
   }
   return GetIconTopLeftColorFromShortcutFile(shortcut_path);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   WebAppProvider* provider = WebAppProvider::GetForLocalAppsUnchecked(profile);
   if (!provider) {
     return std::nullopt;
@@ -476,7 +476,7 @@ base::FilePath OsIntegrationTestOverrideImpl::GetShort
       app_installed_profiles.end()) {
     return shortcut_path;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string shortcut_filename =
       "chrome-" + app_id + "-" + profile->GetBaseName().value() + ".desktop";
   base::FilePath shortcut_path = shortcut_dir.Append(shortcut_filename);
@@ -501,7 +501,7 @@ bool OsIntegrationTestOverrideImpl::IsShortcutCreated(
   base::FilePath app_shortcut_path =
       GetShortcutPath(profile, chrome_apps_folder(), app_id, app_name);
   return base::PathExists(app_shortcut_path);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath desktop_shortcut_path =
       GetShortcutPath(profile, desktop(), app_id, app_name);
   return base::PathExists(desktop_shortcut_path);
@@ -694,7 +694,7 @@ void OsIntegrationTestOverrideImpl::EnableOrDisablePat
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 base::FilePath OsIntegrationTestOverrideImpl::desktop() {
   return desktop_.GetPath();
 }
@@ -745,7 +745,7 @@ OsIntegrationTestOverrideImpl::OsIntegrationTestOverri
   success = chrome_apps_folder_.CreateUniqueTempDirUnderPath(
       outer_temp_dir_.GetPath());
   CHECK(success);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   success = desktop_.CreateUniqueTempDirUnderPath(outer_temp_dir_.GetPath());
   CHECK(success);
   success = startup_.CreateUniqueTempDirUnderPath(outer_temp_dir_.GetPath());
@@ -758,7 +758,7 @@ OsIntegrationTestOverrideImpl::OsIntegrationTestOverri
   CHECK(success);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto callback = base::BindRepeating([](base::FilePath filename_in,
                                          std::string xdg_command,
                                          std::string file_contents) {
@@ -830,7 +830,7 @@ OsIntegrationTestOverrideImpl::~OsIntegrationTestOverr
   EXPECT_TRUE(!startup_.IsValid() || startup_.Delete());
 #elif BUILDFLAG(IS_MAC)
   EXPECT_TRUE(!chrome_apps_folder_.IsValid() || DeleteChromeAppsDir());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_TRUE(!desktop_.IsValid() || desktop_.Delete());
   EXPECT_TRUE(!startup_.IsValid() || startup_.Delete());
   EXPECT_TRUE(!xdg_data_home_dir_.IsValid() || xdg_data_home_dir_.Delete());
