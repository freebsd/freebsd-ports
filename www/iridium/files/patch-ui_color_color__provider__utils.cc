--- ui/color/color_provider_utils.cc.orig	2023-11-22 14:00:11 UTC
+++ ui/color/color_provider_utils.cc
@@ -179,7 +179,7 @@ base::StringPiece SystemThemeName(ui::SystemTheme syst
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
       return "kDefault";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
       return "kGtk";
     case ui::SystemTheme::kQt:
