--- extensions/renderer/bindings/api_binding_util.cc.orig	2021-12-14 11:45:06 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -140,6 +140,8 @@ std::string GetPlatformString() {
   return "win";
 #elif defined(OS_FUCHSIA)
   return "fuchsia";
+#elif defined(OS_BSD)
+  return "bsd";
 #else
   NOTREACHED();
   return std::string();
