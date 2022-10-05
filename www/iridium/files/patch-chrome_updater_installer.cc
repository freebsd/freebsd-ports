--- chrome/updater/installer.cc.orig	2022-10-05 07:34:01 UTC
+++ chrome/updater/installer.cc
@@ -243,7 +243,7 @@ absl::optional<base::FilePath> Installer::GetCurrentIn
   return path->AppendASCII(pv_.GetString());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 AppInstallerResult RunApplicationInstaller(
     const AppInfo& /*app_info*/,
