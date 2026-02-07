--- src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.h
@@ -46,7 +46,7 @@ class HeadlessContentBrowserClient : public content::C
   CreateDevToolsManagerDelegate() override;
   content::GeneratedCodeCacheSettings GetGeneratedCodeCacheSettings(
       content::BrowserContext* context) override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
