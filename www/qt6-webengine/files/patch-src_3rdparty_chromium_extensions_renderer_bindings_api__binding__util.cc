--- src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc
@@ -142,7 +142,7 @@ std::string GetPlatformString() {
 std::string GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
