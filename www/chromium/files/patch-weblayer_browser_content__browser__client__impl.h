--- weblayer/browser/content_browser_client_impl.h.orig	2020-07-07 21:58:19 UTC
+++ weblayer/browser/content_browser_client_impl.h
@@ -101,12 +101,12 @@ class ContentBrowserClientImpl : public content::Conte
   void RenderProcessWillLaunch(content::RenderProcessHost* host) override;
   scoped_refptr<content::QuotaPermissionContext> CreateQuotaPermissionContext()
       override;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
       content::PosixFileDescriptorInfo* mappings) override;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   void AppendExtraCommandLineSwitches(base::CommandLine* command_line,
                                       int child_process_id) override;
 #if defined(OS_ANDROID)
