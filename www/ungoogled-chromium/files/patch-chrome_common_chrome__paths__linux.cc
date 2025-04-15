--- chrome/common/chrome_paths_linux.cc.orig	2025-04-15 08:30:07 UTC
+++ chrome/common/chrome_paths_linux.cc
@@ -93,7 +93,7 @@ bool GetDefaultUserDataDirectory(base::FilePath* resul
 #elif BUILDFLAG(GOOGLE_CHROME_BRANDING)
   std::string data_dir_basename = "google-chrome";
 #else
-  std::string data_dir_basename = "chromium";
+  std::string data_dir_basename = "ungoogled-chromium";
 #endif
   *result = config_dir.Append(data_dir_basename + GetChannelSuffixForDataDir());
   return true;
