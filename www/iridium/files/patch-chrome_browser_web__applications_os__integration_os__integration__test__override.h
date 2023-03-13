--- chrome/browser/web_applications/os_integration/os_integration_test_override.h.orig	2023-03-13 07:33:08 UTC
+++ chrome/browser/web_applications/os_integration/os_integration_test_override.h
@@ -23,7 +23,7 @@ class Profile;
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 struct LinuxFileRegistration {
   std::string xdg_command;
   std::string file_contents;
@@ -145,7 +145,7 @@ class OsIntegrationTestOverride
   }
   void EnableOrDisablePathOnLogin(const base::FilePath& file_path,
                                   bool enable_on_login);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool DeleteDesktopDirOnLinux();
   const base::FilePath& desktop() { return desktop_.GetPath(); }
   const base::FilePath& startup() { return startup_.GetPath(); }
@@ -184,7 +184,7 @@ class OsIntegrationTestOverride
 #elif BUILDFLAG(IS_MAC)
   base::ScopedTempDir chrome_apps_folder_;
   std::map<base::FilePath, bool> startup_enabled_;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedTempDir desktop_;
   base::ScopedTempDir startup_;
   std::vector<LinuxFileRegistration> linux_file_registration_;
