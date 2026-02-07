--- src/3rdparty/chromium/chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -271,6 +271,8 @@ bool ChromeRuntimeAPIDelegate::GetPlatformInfo(Platfor
     info->os = extensions::api::runtime::PLATFORM_OS_CROS;
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_LINUX;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PLATFORM_OS_FREEBSD;
   } else if (strcmp(os, "openbsd") == 0) {
     info->os = extensions::api::runtime::PLATFORM_OS_OPENBSD;
   } else {
