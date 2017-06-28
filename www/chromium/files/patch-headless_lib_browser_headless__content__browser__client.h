--- headless/lib/browser/headless_content_browser_client.h.orig	2017-06-05 19:03:08 UTC
+++ headless/lib/browser/headless_content_browser_client.h
@@ -28,7 +28,7 @@ class HeadlessContentBrowserClient : public content::C
       content::BrowserContext* context,
       content::StoragePartition* partition,
       const storage::OptionalQuotaSettingsCallback& callback) override;
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
