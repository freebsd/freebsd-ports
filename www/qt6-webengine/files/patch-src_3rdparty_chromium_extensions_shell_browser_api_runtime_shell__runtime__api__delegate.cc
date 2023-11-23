--- src/3rdparty/chromium/extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc
@@ -44,7 +44,7 @@ void ShellRuntimeAPIDelegate::OpenURL(const GURL& unin
 bool ShellRuntimeAPIDelegate::GetPlatformInfo(PlatformInfo* info) {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   info->os = api::runtime::PLATFORM_OS_CROS;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   info->os = api::runtime::PLATFORM_OS_LINUX;
 #endif
   return true;
