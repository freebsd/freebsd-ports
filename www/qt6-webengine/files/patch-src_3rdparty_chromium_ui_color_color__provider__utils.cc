--- src/3rdparty/chromium/ui/color/color_provider_utils.cc.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/ui/color/color_provider_utils.cc
@@ -103,7 +103,7 @@ base::StringPiece SystemThemeName(ui::SystemTheme syst
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
       return "kDefault";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
       return "kGtk";
     case ui::SystemTheme::kQt:
