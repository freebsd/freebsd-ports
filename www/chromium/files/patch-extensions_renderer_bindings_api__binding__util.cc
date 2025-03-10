--- extensions/renderer/bindings/api_binding_util.cc.orig	2025-03-05 08:14:56 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -129,7 +129,7 @@ void InvalidateContext(v8::Local<v8::Context> context)
 std::string GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
