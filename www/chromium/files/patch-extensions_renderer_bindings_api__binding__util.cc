--- extensions/renderer/bindings/api_binding_util.cc.orig	2021-09-14 01:51:57 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -136,6 +136,8 @@ std::string GetPlatformString() {
   return "mac";
 #elif defined(OS_WIN)
   return "win";
+#elif defined(OS_BSD)
+  return "bsd";
 #else
   NOTREACHED();
   return std::string();
