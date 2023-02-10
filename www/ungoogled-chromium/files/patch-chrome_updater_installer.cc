--- chrome/updater/installer.cc.orig	2023-01-13 08:56:02 UTC
+++ chrome/updater/installer.cc
@@ -252,7 +252,7 @@ absl::optional<base::FilePath> Installer::GetCurrentIn
   return path->AppendASCII(pv_.GetString());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 AppInstallerResult RunApplicationInstaller(
     const AppInfo& /*app_info*/,
