--- chrome/browser/themes/theme_helper.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/themes/theme_helper.cc
@@ -334,7 +334,7 @@ bool ThemeHelper::ShouldUseIncreasedContrastThemeSuppl
     ui::NativeTheme* native_theme) const {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // On Linux the GTK system theme provides the high contrast colors,
   // so don't use the IncreasedContrastThemeSupplier.
   return false;
