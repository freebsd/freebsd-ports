--- src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc
@@ -128,6 +128,8 @@ std::string GetPlatformString() {
   return "mac";
 #elif defined(OS_WIN)
   return "win";
+#elif defined(OS_BSD)
+  return "bsd";
 #else
   NOTREACHED();
   return std::string();
