--- extensions/renderer/bindings/api_binding_util.cc.orig	2022-02-07 13:39:41 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -132,7 +132,7 @@ std::string GetPlatformString() {
   return "lacros";
 #elif BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   return "chromeos";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return "linux";
 #elif defined(OS_MAC)
   return "mac";
