--- base/files/file_util.cc.orig	2021-09-24 04:25:55 UTC
+++ base/files/file_util.cc
@@ -57,7 +57,7 @@ bool Move(const FilePath& from_path, const FilePath& t
 }
 
 bool CopyFileContents(File& infile, File& outfile) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   bool retry_slow = false;
   bool res =
       internal::CopyFileContentsWithSendfile(infile, outfile, retry_slow);
