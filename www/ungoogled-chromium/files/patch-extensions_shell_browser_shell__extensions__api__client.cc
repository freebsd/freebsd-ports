--- extensions/shell/browser/shell_extensions_api_client.cc.orig	2026-06-05 13:45:06 UTC
+++ extensions/shell/browser/shell_extensions_api_client.cc
@@ -17,7 +17,7 @@
 #include "extensions/shell/browser/shell_display_info_provider.h"
 #include "extensions/shell/browser/shell_extension_web_contents_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/shell/browser/api/file_system/shell_file_system_delegate.h"
 #endif
 
@@ -85,7 +85,7 @@ ShellExtensionsAPIClient::CreateDisplayInfoProvider() 
   return std::make_unique<ShellDisplayInfoProvider>();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 FileSystemDelegate* ShellExtensionsAPIClient::GetFileSystemDelegate() {
   if (!file_system_delegate_)
     file_system_delegate_ = std::make_unique<ShellFileSystemDelegate>();
