--- extensions/renderer/bindings/api_binding_util.cc.orig	2018-12-12 22:56:08.000000000 +0100
+++ extensions/renderer/bindings/api_binding_util.cc	2018-12-30 03:38:04.191665000 +0100
@@ -129,6 +129,8 @@
   return "mac";
 #elif defined(OS_WIN)
   return "win";
+#elif defined(OS_BSD)
+  return "bsd";
 #else
   NOTREACHED();
   return std::string();
