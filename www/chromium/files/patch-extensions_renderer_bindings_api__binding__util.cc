--- extensions/renderer/bindings/api_binding_util.cc.orig	2020-11-13 06:36:43 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -130,6 +130,8 @@ std::string GetPlatformString() {
   return "mac";
 #elif defined(OS_WIN)
   return "win";
+#elif defined(OS_BSD)
+  return "bsd";
 #else
   NOTREACHED();
   return std::string();
