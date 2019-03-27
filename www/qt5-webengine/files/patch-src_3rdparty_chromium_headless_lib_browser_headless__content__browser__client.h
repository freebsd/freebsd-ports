--- src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.h
@@ -32,7 +32,7 @@ class HeadlessContentBrowserClient : public content::C
       content::BrowserContext* context,
       content::StoragePartition* partition,
       storage::OptionalQuotaSettingsCallback callback) override;
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
