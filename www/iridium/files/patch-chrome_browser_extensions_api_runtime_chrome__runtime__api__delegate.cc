--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -361,7 +361,9 @@ bool ChromeRuntimeAPIDelegate::GetPlatformInfo(Platfor
   } else if (os == "linux") {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (os == "openbsd") {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (os == "freebsd") {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (os == "android") {
     info->os = extensions::api::runtime::PlatformOs::kAndroid;
   } else {
