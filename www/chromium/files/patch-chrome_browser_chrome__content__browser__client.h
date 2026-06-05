--- chrome/browser/chrome_content_browser_client.h.orig	2026-06-04 10:12:25 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -576,7 +576,7 @@ class ChromeContentBrowserClient : public content::Con
       const GURL& site_url) override;
   std::unique_ptr<content::TracingDelegate> CreateTracingDelegate() override;
   bool IsSystemWideTracingEnabled() override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
