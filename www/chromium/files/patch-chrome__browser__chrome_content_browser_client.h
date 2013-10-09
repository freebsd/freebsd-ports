--- chrome/browser/chrome_content_browser_client.h.orig	2013-09-25 22:20:01.000000000 +0300
+++ chrome/browser/chrome_content_browser_client.h	2013-09-25 22:20:17.000000000 +0300
@@ -248,7 +248,7 @@
       const base::FilePath& storage_partition_path,
       ScopedVector<fileapi::FileSystemBackend>* additional_backends) OVERRIDE;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   virtual void GetAdditionalMappedFilesForChildProcess(
       const CommandLine& command_line,
       int child_process_id,
