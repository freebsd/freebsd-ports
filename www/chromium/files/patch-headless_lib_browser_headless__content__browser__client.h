--- headless/lib/browser/headless_content_browser_client.h.orig	2019-01-30 02:18:02.000000000 +0100
+++ headless/lib/browser/headless_content_browser_client.h	2019-02-01 09:56:18.585343000 +0100
@@ -34,7 +34,7 @@
       ::storage::OptionalQuotaSettingsCallback callback) override;
   content::GeneratedCodeCacheSettings GetGeneratedCodeCacheSettings(
       content::BrowserContext* context) override;
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
