--- weblayer/browser/content_browser_client_impl.h.orig	2020-01-07 21:53:35 UTC
+++ weblayer/browser/content_browser_client_impl.h
@@ -80,12 +80,12 @@ class ContentBrowserClientImpl : public content::Conte
       base::OnceCallback<void(base::Optional<storage::QuotaSettings>)> callback)
       override;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
       content::PosixFileDescriptorInfo* mappings) override;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
   bool ShouldOverrideUrlLoading(int frame_tree_node_id,
