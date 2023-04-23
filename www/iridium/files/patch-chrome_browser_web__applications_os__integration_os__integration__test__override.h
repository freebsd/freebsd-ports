--- chrome/browser/web_applications/os_integration/os_integration_test_override.h.orig	2023-04-22 17:45:15 UTC
+++ chrome/browser/web_applications/os_integration/os_integration_test_override.h
@@ -33,7 +33,7 @@ class ShellLinkItem;
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 struct LinuxFileRegistration {
   std::string xdg_command;
   std::string file_contents;
@@ -183,7 +183,7 @@ class OsIntegrationTestOverride
   }
   void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                   bool enable_on_login);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool DeleteDesktopDirOnLinux();
   const base::FilePath& desktop() { return desktop_.GetPath(); }
   const base::FilePath& startup() { return startup_.GetPath(); }
@@ -230,7 +230,7 @@ class OsIntegrationTestOverride
 #elif BUILDFLAG(IS_MAC)
   base::ScopedTempDir chrome_apps_folder_;
   std::map<base::FilePath, bool> startup_enabled_;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedTempDir desktop_;
   base::ScopedTempDir startup_;
   std::vector<LinuxFileRegistration> linux_file_registration_;
