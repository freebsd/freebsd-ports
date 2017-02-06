--- chrome/browser/renderer_preferences_util.cc.orig	2017-01-26 00:49:08 UTC
+++ chrome/browser/renderer_preferences_util.cc
@@ -19,7 +19,7 @@
 #include "third_party/WebKit/public/public_features.h"
 #include "third_party/skia/include/core/SkColor.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "ui/gfx/font_render_params.h"
 #endif
 
@@ -31,7 +31,7 @@
 #include "ui/base/cocoa/defaults_utils.h"
 #endif
 
-#if defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "ui/views/linux_ui/linux_ui.h"
@@ -133,7 +133,7 @@ void UpdateFromSystemSettings(content::R
     prefs->caret_blink_interval = interval.InSecondsF();
 #endif
 
-#if defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
   if (linux_ui) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
@@ -155,7 +155,7 @@ void UpdateFromSystemSettings(content::R
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_BSD)
   CR_DEFINE_STATIC_LOCAL(const gfx::FontRenderParams, params,
       (gfx::GetFontRenderParams(gfx::FontRenderParamsQuery(), NULL)));
   prefs->should_antialias_text = params.antialiasing;
