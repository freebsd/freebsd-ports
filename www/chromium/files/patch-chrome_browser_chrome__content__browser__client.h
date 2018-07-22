--- chrome/browser/chrome_content_browser_client.h.orig	2018-06-13 00:10:04.000000000 +0200
+++ chrome/browser/chrome_content_browser_client.h	2018-07-14 14:13:02.407023000 +0200
@@ -299,12 +299,12 @@
   void OverridePageVisibilityState(
       content::RenderFrameHost* render_frame_host,
       blink::mojom::PageVisibilityState* visibility_state) override;
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
