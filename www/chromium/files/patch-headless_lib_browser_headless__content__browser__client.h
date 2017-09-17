--- headless/lib/browser/headless_content_browser_client.h.orig	2017-09-05 21:05:20.000000000 +0200
+++ headless/lib/browser/headless_content_browser_client.h	2017-09-06 20:33:27.212197000 +0200
@@ -30,7 +30,7 @@
       content::BrowserContext* context,
       content::StoragePartition* partition,
       storage::OptionalQuotaSettingsCallback callback) override;
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
