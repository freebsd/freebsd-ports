--- src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/extensions/renderer/bindings/api_binding_util.cc
@@ -132,7 +132,7 @@ std::string GetPlatformString() {
   return "lacros";
 #elif BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
