--- chrome/common/chrome_paths_linux.cc.orig	2022-10-09 05:56:28 UTC
+++ chrome/common/chrome_paths_linux.cc
@@ -92,7 +92,7 @@ bool GetDefaultUserDataDirectory(base::FilePath* resul
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   std::string data_dir_basename = "google-chrome";
 #else
-  std::string data_dir_basename = "chromium";
+  std::string data_dir_basename = "ungoogled-chromium";
 #endif
   *result = config_dir.Append(data_dir_basename + GetChannelSuffixForDataDir());
   return true;
