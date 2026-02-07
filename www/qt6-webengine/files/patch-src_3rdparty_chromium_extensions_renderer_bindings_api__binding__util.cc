--- src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc
@@ -129,7 +129,7 @@ std::string GetPlatformString() {
 std::string GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
