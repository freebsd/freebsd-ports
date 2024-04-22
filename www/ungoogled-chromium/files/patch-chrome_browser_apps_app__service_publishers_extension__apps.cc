--- chrome/browser/apps/app_service/publishers/extension_apps.cc.orig	2024-02-03 15:42:55 UTC
+++ chrome/browser/apps/app_service/publishers/extension_apps.cc
@@ -24,7 +24,7 @@ ExtensionApps::~ExtensionApps() = default;
 
 bool ExtensionApps::Accepts(const extensions::Extension* extension) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile(),
                                                       extension->id())) {
     return false;
