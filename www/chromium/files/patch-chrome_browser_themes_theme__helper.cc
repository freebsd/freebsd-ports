--- chrome/browser/themes/theme_helper.cc.orig	2021-04-22 07:57:50 UTC
+++ chrome/browser/themes/theme_helper.cc
@@ -304,7 +304,7 @@ bool ThemeHelper::ShouldUseIncreasedContrastThemeSuppl
     ui::NativeTheme* native_theme) const {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // On Linux the GTK system theme provides the high contrast colors,
   // so don't use the IncreasedContrastThemeSupplier.
   return false;
