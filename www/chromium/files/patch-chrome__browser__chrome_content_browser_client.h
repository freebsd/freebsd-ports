--- chrome/browser/chrome_content_browser_client.h.orig	2015-09-03 09:44:27.080480000 -0400
+++ chrome/browser/chrome_content_browser_client.h	2015-09-03 09:44:46.151235000 -0400
@@ -253,7 +253,7 @@
       int child_process_id,
       content::FileDescriptorInfo* mappings,
       std::map<int, base::MemoryMappedFile::Region>* regions) override;
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
