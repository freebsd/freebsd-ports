--- base/files/file_util.cc.orig	2021-07-28 07:18:23 UTC
+++ base/files/file_util.cc
@@ -52,7 +52,7 @@ bool Move(const FilePath& from_path, const FilePath& t
 }
 
 bool CopyFileContents(File& infile, File& outfile) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   bool retry_slow = false;
   bool res =
       internal::CopyFileContentsWithSendfile(infile, outfile, retry_slow);
