--- headless/lib/browser/headless_content_browser_client.h.orig	2017-05-09 19:02:47 UTC
+++ headless/lib/browser/headless_content_browser_client.h
@@ -28,7 +28,7 @@ class HeadlessContentBrowserClient : pub
       content::BrowserContext* context,
       content::StoragePartition* partition,
       const storage::OptionalQuotaSettingsCallback& callback) override;
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
