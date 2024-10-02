--- chrome/browser/ui/webui/chrome_web_ui_configs.cc.orig	2024-10-01 07:26:23 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_configs.cc
@@ -110,10 +110,10 @@ void RegisterChromeWebUIConfigs() {
   map.AddWebUIConfig(std::make_unique<TermsUIConfig>());
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   map.AddWebUIConfig(std::make_unique<LinuxProxyConfigUI>());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_OPENBSD)
+        // BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(ENABLE_EXTENSIONS)
   map.AddWebUIConfig(std::make_unique<extensions::ExtensionsUIConfig>());
