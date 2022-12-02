--- chrome/updater/installer.cc.orig	2022-12-02 17:56:32 UTC
+++ chrome/updater/installer.cc
@@ -250,7 +250,7 @@ absl::optional<base::FilePath> Installer::GetCurrentIn
   return path->AppendASCII(pv_.GetString());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 AppInstallerResult RunApplicationInstaller(
     const AppInfo& /*app_info*/,
