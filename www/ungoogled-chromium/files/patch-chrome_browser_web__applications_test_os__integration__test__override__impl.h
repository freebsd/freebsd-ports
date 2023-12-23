--- chrome/browser/web_applications/test/os_integration_test_override_impl.h.orig	2023-12-23 12:33:28 UTC
+++ chrome/browser/web_applications/test/os_integration_test_override_impl.h
@@ -38,7 +38,7 @@ class ShellLinkItem;
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 struct LinuxFileRegistration {
   base::FilePath file_name;
   std::string xdg_command;
@@ -112,7 +112,7 @@ class OsIntegrationTestOverrideImpl : public OsIntegra
   bool DeleteApplicationMenuDirOnWin();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool DeleteDesktopDirOnLinux();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -231,7 +231,7 @@ class OsIntegrationTestOverrideImpl : public OsIntegra
   const base::FilePath& chrome_apps_folder() override;
   void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                   bool enable_on_login) override;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::FilePath& desktop() override;
   const base::FilePath& startup() override;
   const base::FilePath& applications_dir() override;
@@ -278,7 +278,7 @@ class OsIntegrationTestOverrideImpl : public OsIntegra
   base::ScopedTempDir chrome_apps_folder_;
   std::map<base::FilePath, bool> startup_enabled_;
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedTempDir desktop_;
   base::ScopedTempDir startup_;
   base::ScopedTempDir applications_dir_;
