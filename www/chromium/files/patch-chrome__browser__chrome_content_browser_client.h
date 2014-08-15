--- ./chrome/browser/chrome_content_browser_client.h.orig	2014-08-12 21:01:48.000000000 +0200
+++ ./chrome/browser/chrome_content_browser_client.h	2014-08-13 09:56:56.000000000 +0200
@@ -260,7 +260,7 @@
       const base::FilePath& storage_partition_path,
       ScopedVector<fileapi::FileSystemBackend>* additional_backends) OVERRIDE;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   virtual void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
