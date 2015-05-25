--- chrome/browser/renderer_preferences_util.cc.orig	2015-05-13 18:35:45.000000000 -0400
+++ chrome/browser/renderer_preferences_util.cc     2015-05-20 09:51:41.644579000 -0400
@@ -13,7 +13,7 @@
 #include "content/public/common/renderer_preferences.h"
 #include "third_party/skia/include/core/SkColor.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "ui/gfx/font_render_params.h"
 #endif
 
@@ -25,7 +25,7 @@
 #include "ui/views/controls/textfield/textfield.h"
 #endif
 
-#if defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "ui/views/linux_ui/linux_ui.h"
@@ -84,7 +84,7 @@
   prefs->caret_blink_interval = views::Textfield::GetCaretBlinkMs() / 1000.0;
 #endif
 
-#if defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
   if (linux_ui) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
@@ -106,7 +106,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_BSD)
   CR_DEFINE_STATIC_LOCAL(const gfx::FontRenderParams, params,
       (gfx::GetFontRenderParams(gfx::FontRenderParamsQuery(true), NULL)));
   prefs->should_antialias_text = params.antialiasing;
