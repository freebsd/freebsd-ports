--- src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.h
@@ -34,14 +34,14 @@ class ShellExtensionsAPIClient : public ExtensionsAPIC
       content::BrowserContext* browser_context) const override;
   std::unique_ptr<DisplayInfoProvider> CreateDisplayInfoProvider()
       const override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   FileSystemDelegate* GetFileSystemDelegate() override;
 #endif
   MessagingDelegate* GetMessagingDelegate() override;
   FeedbackPrivateDelegate* GetFeedbackPrivateDelegate() override;
 
  private:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<FileSystemDelegate> file_system_delegate_;
 #endif
   std::unique_ptr<MessagingDelegate> messaging_delegate_;
