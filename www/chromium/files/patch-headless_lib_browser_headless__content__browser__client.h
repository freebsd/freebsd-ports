--- headless/lib/browser/headless_content_browser_client.h.orig	2018-12-03 21:16:59.000000000 +0100
+++ headless/lib/browser/headless_content_browser_client.h	2018-12-13 23:21:30.880956000 +0100
@@ -32,7 +32,7 @@
       content::BrowserContext* context,
       content::StoragePartition* partition,
       ::storage::OptionalQuotaSettingsCallback callback) override;
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
