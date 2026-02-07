--- src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/extensions/shell/browser/shell_extensions_api_client.cc
@@ -18,7 +18,7 @@
 #include "extensions/shell/browser/shell_virtual_keyboard_delegate.h"
 #include "extensions/shell/browser/shell_web_view_guest_delegate.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/shell/browser/api/file_system/shell_file_system_delegate.h"
 #endif
 
@@ -54,7 +54,7 @@ ShellExtensionsAPIClient::CreateDisplayInfoProvider() 
   return std::make_unique<ShellDisplayInfoProvider>();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 FileSystemDelegate* ShellExtensionsAPIClient::GetFileSystemDelegate() {
   if (!file_system_delegate_)
     file_system_delegate_ = std::make_unique<ShellFileSystemDelegate>();
