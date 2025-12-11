--- chrome/browser/themes/theme_service_aura_linux.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/themes/theme_service_aura_linux.cc
@@ -23,7 +23,7 @@ namespace {
 ui::SystemTheme ValidateSystemTheme(ui::SystemTheme system_theme) {
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
     case ui::SystemTheme::kQt:
 #endif
