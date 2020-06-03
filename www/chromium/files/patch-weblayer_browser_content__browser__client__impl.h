--- weblayer/browser/content_browser_client_impl.h.orig	2020-05-13 18:40:37 UTC
+++ weblayer/browser/content_browser_client_impl.h
@@ -91,12 +91,12 @@ class ContentBrowserClientImpl : public content::Conte
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
 
   void CreateFeatureListAndFieldTrials();
 
