--- chrome/browser/chrome_content_browser_client.h.orig	2017-12-15 02:04:08.000000000 +0100
+++ chrome/browser/chrome_content_browser_client.h	2017-12-24 00:50:35.917227000 +0100
@@ -291,12 +291,12 @@
       content::RenderFrameHost* render_frame_host,
       blink::WebPageVisibilityState* visibility_state) override;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
       content::PosixFileDescriptorInfo* mappings) override;
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #if defined(OS_WIN)
   bool PreSpawnRenderer(sandbox::TargetPolicy* policy) override;
   base::string16 GetAppContainerSidForSandboxType(
