--- chrome/browser/apps/app_service/publishers/extension_apps.cc.orig	2024-04-23 07:42:17 UTC
+++ chrome/browser/apps/app_service/publishers/extension_apps.cc
@@ -23,7 +23,7 @@ ExtensionApps::ExtensionApps(AppServiceProxy* proxy)
 ExtensionApps::~ExtensionApps() = default;
 
 bool ExtensionApps::Accepts(const extensions::Extension* extension) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile(),
                                                       extension->id())) {
     return false;
