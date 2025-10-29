--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -353,7 +353,9 @@ bool ChromeRuntimeAPIDelegate::GetPlatformInfo(Platfor
   } else if (UNSAFE_TODO(strcmp(os, "linux")) == 0) {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (UNSAFE_TODO(strcmp(os, "openbsd")) == 0) {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (UNSAFE_TODO(strcmp(os, "freebsd")) == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (UNSAFE_TODO(strcmp(os, "android")) == 0) {
     info->os = extensions::api::runtime::PlatformOs::kAndroid;
   } else {
