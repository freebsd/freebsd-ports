--- extensions/renderer/bindings/api_binding_util.cc.orig	2021-03-12 23:57:25 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -131,6 +131,8 @@ std::string GetPlatformString() {
   return "mac";
 #elif defined(OS_WIN)
   return "win";
+#elif defined(OS_BSD)
+  return "bsd";
 #else
   NOTREACHED();
   return std::string();
