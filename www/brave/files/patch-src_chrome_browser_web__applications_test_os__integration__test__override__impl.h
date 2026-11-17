--- src/chrome/browser/web_applications/test/os_integration_test_override_impl.h.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/web_applications/test/os_integration_test_override_impl.h
@@ -41,7 +41,7 @@ class ShellLinkItem;
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 struct LinuxFileRegistration {
   base::FilePath file_name;
   std::string xdg_command;
@@ -138,7 +138,7 @@ class OsIntegrationTestOverrideImpl : pu
   bool DeleteApplicationMenuDirOnWin();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool DeleteDesktopDirOnLinux();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -276,7 +276,7 @@ class OsIntegrationTestOverrideImpl : pu
   base::FilePath chrome_apps_folder() override;
   void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                   bool enable_on_login) override;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath desktop();
   base::FilePath startup();
   base::FilePath applications();
@@ -349,7 +349,7 @@ class OsIntegrationTestOverrideImpl : pu
   base::ScopedTempDir chrome_apps_folder_;
   std::map<base::FilePath, bool> startup_enabled_;
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedTempDir desktop_;
   base::ScopedTempDir startup_;
   base::ScopedTempDir xdg_data_home_dir_;
