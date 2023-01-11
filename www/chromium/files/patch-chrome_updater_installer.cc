--- chrome/updater/installer.cc.orig	2023-01-11 09:17:16 UTC
+++ chrome/updater/installer.cc
@@ -252,7 +252,7 @@ absl::optional<base::FilePath> Installer::GetCurrentIn
   return path->AppendASCII(pv_.GetString());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 AppInstallerResult RunApplicationInstaller(
     const AppInfo& /*app_info*/,
