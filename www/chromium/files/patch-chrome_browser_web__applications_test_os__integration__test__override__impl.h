--- chrome/browser/web_applications/test/os_integration_test_override_impl.h.orig	2024-05-21 18:07:39 UTC
+++ chrome/browser/web_applications/test/os_integration_test_override_impl.h
@@ -40,7 +40,7 @@ class ShellLinkItem;
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 struct LinuxFileRegistration {
   base::FilePath file_name;
   std::string xdg_command;
@@ -116,7 +116,7 @@ class OsIntegrationTestOverrideImpl : public OsIntegra
   bool DeleteApplicationMenuDirOnWin();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool DeleteDesktopDirOnLinux();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -235,7 +235,7 @@ class OsIntegrationTestOverrideImpl : public OsIntegra
   base::FilePath chrome_apps_folder() override;
   void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                   bool enable_on_login) override;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath desktop();
   base::FilePath startup();
   base::FilePath applications();
@@ -315,7 +315,7 @@ class OsIntegrationTestOverrideImpl : public OsIntegra
   base::ScopedTempDir chrome_apps_folder_;
   std::map<base::FilePath, bool> startup_enabled_;
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedTempDir desktop_;
   base::ScopedTempDir startup_;
   base::ScopedTempDir xdg_data_home_dir_;
