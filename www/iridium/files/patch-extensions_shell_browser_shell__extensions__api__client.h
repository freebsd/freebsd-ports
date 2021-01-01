--- extensions/shell/browser/shell_extensions_api_client.h.orig	2019-09-09 21:55:17 UTC
+++ extensions/shell/browser/shell_extensions_api_client.h
@@ -32,14 +32,14 @@ class ShellExtensionsAPIClient : public ExtensionsAPIC
       content::BrowserContext* browser_context) const override;
   std::unique_ptr<DisplayInfoProvider> CreateDisplayInfoProvider()
       const override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   FileSystemDelegate* GetFileSystemDelegate() override;
 #endif
   MessagingDelegate* GetMessagingDelegate() override;
   FeedbackPrivateDelegate* GetFeedbackPrivateDelegate() override;
 
  private:
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   std::unique_ptr<FileSystemDelegate> file_system_delegate_;
 #endif
   std::unique_ptr<MessagingDelegate> messaging_delegate_;
