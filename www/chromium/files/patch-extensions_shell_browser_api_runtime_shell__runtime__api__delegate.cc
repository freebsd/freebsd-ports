--- extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc.orig	2020-11-13 06:36:43 UTC
+++ extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc
@@ -45,7 +45,7 @@ void ShellRuntimeAPIDelegate::OpenURL(const GURL& unin
 bool ShellRuntimeAPIDelegate::GetPlatformInfo(PlatformInfo* info) {
 #if defined(OS_CHROMEOS)
   info->os = api::runtime::PLATFORM_OS_CROS;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   info->os = api::runtime::PLATFORM_OS_LINUX;
 #endif
   return true;
