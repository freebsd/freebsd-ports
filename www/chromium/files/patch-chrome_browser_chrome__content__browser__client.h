--- chrome/browser/chrome_content_browser_client.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -412,7 +412,7 @@ class ChromeContentBrowserClient : public content::Con
   void OverridePageVisibilityState(
       content::RenderFrameHost* render_frame_host,
       content::PageVisibilityState* visibility_state) override;
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
