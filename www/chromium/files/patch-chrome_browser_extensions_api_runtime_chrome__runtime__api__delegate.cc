--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -279,7 +279,9 @@ bool ChromeRuntimeAPIDelegate::GetPlatformInfo(Platfor
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "openbsd") == 0) {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "fuchsia") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kFuchsia;
   } else {
