--- headless/lib/browser/headless_content_browser_client.h.orig	2019-10-21 19:06:35 UTC
+++ headless/lib/browser/headless_content_browser_client.h
@@ -33,7 +33,7 @@ class HeadlessContentBrowserClient : public content::C
       ::storage::OptionalQuotaSettingsCallback callback) override;
   content::GeneratedCodeCacheSettings GetGeneratedCodeCacheSettings(
       content::BrowserContext* context) override;
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
