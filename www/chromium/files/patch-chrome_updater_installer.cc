--- chrome/updater/installer.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/updater/installer.cc
@@ -225,7 +225,7 @@ absl::optional<base::FilePath> Installer::GetCurrentIn
   return path->AppendASCII(pv_.GetString());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 Installer::Result Installer::RunApplicationInstaller(
     const base::FilePath& /*app_installer*/,
     const std::string& /*arguments*/,
