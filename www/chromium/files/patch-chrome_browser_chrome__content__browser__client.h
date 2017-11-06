--- chrome/browser/chrome_content_browser_client.h.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -271,12 +271,12 @@ class ChromeContentBrowserClient : public content::Con
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
