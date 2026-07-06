--- chrome/browser/chrome_content_browser_client.h.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -585,7 +585,7 @@ class ChromeContentBrowserClient : public content::Con
       const GURL& site_url) override;
   std::unique_ptr<content::TracingDelegate> CreateTracingDelegate() override;
   bool IsSystemWideTracingEnabled() override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
