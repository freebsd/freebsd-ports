--- chrome/browser/themes/theme_helper.cc.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/themes/theme_helper.cc
@@ -24,7 +24,7 @@
 #include "ui/native_theme/common_theme.h"
 #include "ui/native_theme/native_theme.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -498,7 +498,7 @@ bool ThemeHelper::UseDarkModeColors(const CustomThemeS
 
   ui::NativeTheme const* native_theme =
       ui::NativeTheme::GetInstanceForNativeUi();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (const auto* linux_ui = views::LinuxUI::instance()) {
     // We rely on the fact that the system theme is in use iff `theme_supplier`
     // is non-null, but this is cheating. In the future this might not hold
