--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2021-09-14 01:51:50 UTC
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -285,6 +285,8 @@ bool ChromeRuntimeAPIDelegate::GetPlatformInfo(Platfor
     info->os = extensions::api::runtime::PLATFORM_OS_CROS;
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_LINUX;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PLATFORM_OS_FREEBSD;
   } else if (strcmp(os, "openbsd") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_OPENBSD;
   } else {
