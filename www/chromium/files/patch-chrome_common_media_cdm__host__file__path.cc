--- chrome/common/media/cdm_host_file_path.cc.orig	2020-07-07 21:58:14 UTC
+++ chrome/common/media/cdm_host_file_path.cc
@@ -93,7 +93,7 @@ void AddCdmHostFilePaths(
   cdm_host_file_paths->emplace_back(chrome_framework_path,
                                     chrome_framework_sig_path);
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 
   base::FilePath chrome_exe_dir;
   if (!base::PathService::Get(base::DIR_EXE, &chrome_exe_dir))
