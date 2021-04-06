--- chrome/browser/plugins/plugins_resource_service.cc.orig	2021-03-12 23:57:18 UTC
+++ chrome/browser/plugins/plugins_resource_service.cc
@@ -62,7 +62,7 @@ GURL GetPluginsServerURL() {
   filename = "plugins_win.json";
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   filename = "plugins_chromeos.json";
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   filename = "plugins_linux.json";
 #elif defined(OS_MAC)
   filename = "plugins_mac.json";
