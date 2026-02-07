--- chrome/common/chrome_paths_linux.cc.orig	2025-12-12 07:44:27 UTC
+++ chrome/common/chrome_paths_linux.cc
@@ -95,7 +95,7 @@ bool GetDefaultUserDataDirectory(base::FilePath* resul
 #elif BUILDFLAG(GOOGLE_CHROME_BRANDING)
   std::string data_dir_basename = "google-chrome";
 #else
-  std::string data_dir_basename = "chromium";
+  std::string data_dir_basename = "ungoogled-chromium";
 #endif
   *result = config_dir.Append(data_dir_basename + GetChannelSuffixForDataDir());
   return true;
