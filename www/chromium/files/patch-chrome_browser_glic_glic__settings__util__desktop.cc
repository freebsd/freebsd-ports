--- chrome/browser/glic/glic_settings_util_desktop.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/glic/glic_settings_util_desktop.cc
@@ -122,7 +122,7 @@ std::string_view GetPlatformHelpSuffix() {
   return "_mac";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "_chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "_linux";
 #else
   return "";
