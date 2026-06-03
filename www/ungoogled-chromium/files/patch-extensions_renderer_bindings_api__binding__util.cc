--- extensions/renderer/bindings/api_binding_util.cc.orig	2026-04-15 11:25:12 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -142,7 +142,7 @@ void InvalidateContext(v8::Local<v8::Context> context)
 std::string_view GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
