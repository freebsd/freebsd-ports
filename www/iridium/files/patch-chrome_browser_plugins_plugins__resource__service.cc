--- chrome/browser/plugins/plugins_resource_service.cc.orig	2022-03-28 18:11:04 UTC
+++ chrome/browser/plugins/plugins_resource_service.cc
@@ -62,7 +62,7 @@ GURL GetPluginsServerURL() {
   filename = "plugins_win.json";
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   filename = "plugins_chromeos.json";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   filename = "plugins_linux.json";
 #elif BUILDFLAG(IS_MAC)
   filename = "plugins_mac.json";
