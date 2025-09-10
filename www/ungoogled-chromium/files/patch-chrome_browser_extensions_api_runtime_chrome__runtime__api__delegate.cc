--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -356,7 +356,9 @@ bool ChromeRuntimeAPIDelegate::GetPlatformInfo(Platfor
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "openbsd") == 0) {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "android") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kAndroid;
   } else {
