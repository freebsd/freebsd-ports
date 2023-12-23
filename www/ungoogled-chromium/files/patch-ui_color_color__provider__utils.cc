--- ui/color/color_provider_utils.cc.orig	2023-12-23 12:33:28 UTC
+++ ui/color/color_provider_utils.cc
@@ -187,7 +187,7 @@ base::StringPiece SystemThemeName(ui::SystemTheme syst
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
       return "kDefault";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
       return "kGtk";
     case ui::SystemTheme::kQt:
