--- chrome/browser/chrome_content_browser_client.h.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -270,12 +270,12 @@ class ChromeContentBrowserClient : publi
       content::RenderFrameHost* render_frame_host,
       blink::WebPageVisibilityState* visibility_state) override;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
       content::FileDescriptorInfo* mappings) override;
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #if defined(OS_WIN)
   bool PreSpawnRenderer(sandbox::TargetPolicy* policy) override;
   base::string16 GetAppContainerSidForSandboxType(
