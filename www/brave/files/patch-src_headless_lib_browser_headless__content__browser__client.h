--- src/headless/lib/browser/headless_content_browser_client.h.orig	2026-10-18 18:43:23 UTC
+++ src/headless/lib/browser/headless_content_browser_client.h
@@ -48,7 +48,7 @@ class HeadlessContentBrowserClient : pub
   CreateDevToolsManagerDelegate() override;
   content::GeneratedCodeCacheSettings GetGeneratedCodeCacheSettings(
       content::BrowserContext* context) override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
