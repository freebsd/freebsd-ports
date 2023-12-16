--- src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.h.orig	2022-02-28 16:54:41 UTC
+++ src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.h
@@ -36,7 +36,7 @@ class ShellExtensionsAPIClient : public ExtensionsAPIC
       const override;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   FileSystemDelegate* GetFileSystemDelegate() override;
 #endif
   MessagingDelegate* GetMessagingDelegate() override;
@@ -45,7 +45,7 @@ class ShellExtensionsAPIClient : public ExtensionsAPIC
  private:
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<FileSystemDelegate> file_system_delegate_;
 #endif
   std::unique_ptr<MessagingDelegate> messaging_delegate_;
