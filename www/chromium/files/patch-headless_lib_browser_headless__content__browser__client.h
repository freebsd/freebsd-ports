--- headless/lib/browser/headless_content_browser_client.h.orig	2026-11-19 12:25:27 UTC
+++ headless/lib/browser/headless_content_browser_client.h
@@ -49,7 +49,7 @@ class HeadlessContentBrowserClient : public content::C
   CreateDevToolsManagerDelegate() override;
   content::GeneratedCodeCacheSettings GetGeneratedCodeCacheSettings(
       content::BrowserContext* context) override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
