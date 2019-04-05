--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -296,6 +296,8 @@ bool ChromeRuntimeAPIDelegate::GetPlatformInfo(Platfor
     info->os = extensions::api::runtime::PLATFORM_OS_CROS;
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_LINUX;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PLATFORM_OS_FREEBSD;
   } else if (strcmp(os, "openbsd") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_OPENBSD;
   } else {
