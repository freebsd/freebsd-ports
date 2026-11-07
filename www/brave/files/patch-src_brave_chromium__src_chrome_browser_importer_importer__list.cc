--- src/brave/chromium_src/chrome/browser/importer/importer_list.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/chrome/browser/importer/importer_list.cc
@@ -74,7 +74,7 @@
           base::FilePath::StringType(FILE_PATH_LITERAL("Local State")))),
       GetChromeDevUserDataFolder(), kGoogleChromeBrowserDev,
       user_data_importer::TYPE_CHROME);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   AddChromeToProfiles(
       profiles,
       GetChromeSourceProfiles(GetCanaryUserDataFolder().Append(
