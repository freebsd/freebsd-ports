--- ./chrome/browser/chrome_content_browser_client.h.orig	2014-04-24 22:35:13.000000000 +0200
+++ ./chrome/browser/chrome_content_browser_client.h	2014-04-24 23:23:42.000000000 +0200
@@ -255,7 +255,7 @@
       const base::FilePath& storage_partition_path,
       ScopedVector<fileapi::FileSystemBackend>* additional_backends) OVERRIDE;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   virtual void GetAdditionalMappedFilesForChildProcess(
       const CommandLine& command_line,
       int child_process_id,
