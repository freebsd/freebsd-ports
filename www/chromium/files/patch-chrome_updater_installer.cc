--- chrome/updater/installer.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/updater/installer.cc
@@ -228,7 +228,7 @@ absl::optional<base::FilePath> Installer::GetCurrentIn
   return path->AppendASCII(pv_.GetString());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 Installer::Result Installer::RunApplicationInstaller(
     const base::FilePath& /*app_installer*/,
     const std::string& /*arguments*/,
