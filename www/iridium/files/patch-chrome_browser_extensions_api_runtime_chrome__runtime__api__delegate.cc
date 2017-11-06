--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2017-05-09 19:02:41 UTC
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -277,6 +277,8 @@ bool ChromeRuntimeAPIDelegate::GetPlatfo
     info->os = extensions::api::runtime::PLATFORM_OS_CROS;
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_LINUX;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PLATFORM_OS_FREEBSD;
   } else if (strcmp(os, "openbsd") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_OPENBSD;
   } else {
