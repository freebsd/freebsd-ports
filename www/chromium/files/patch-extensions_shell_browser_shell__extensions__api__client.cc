--- extensions/shell/browser/shell_extensions_api_client.cc.orig	2021-04-14 18:41:04 UTC
+++ extensions/shell/browser/shell_extensions_api_client.cc
@@ -19,7 +19,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "extensions/shell/browser/api/file_system/shell_file_system_delegate.h"
 #endif
 
@@ -57,7 +57,7 @@ ShellExtensionsAPIClient::CreateDisplayInfoProvider() 
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 FileSystemDelegate* ShellExtensionsAPIClient::GetFileSystemDelegate() {
   if (!file_system_delegate_)
     file_system_delegate_ = std::make_unique<ShellFileSystemDelegate>();
