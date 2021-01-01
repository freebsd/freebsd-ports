--- chromecast/browser/cast_browser_main_parts.cc.orig	2020-03-16 18:40:30 UTC
+++ chromecast/browser/cast_browser_main_parts.cc
@@ -74,7 +74,7 @@
 #include "ui/base/ui_base_switches.h"
 #include "ui/gl/gl_switches.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fontconfig/fontconfig.h>
 #include <signal.h>
 #include <sys/prctl.h>
@@ -263,7 +263,7 @@ class CastViewsDelegate : public views::ViewsDelegate 
 
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 base::FilePath GetApplicationFontsDir() {
   std::unique_ptr<base::Environment> env(base::Environment::Create());
@@ -279,7 +279,7 @@ base::FilePath GetApplicationFontsDir() {
   }
 }
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace
 
@@ -308,7 +308,7 @@ const DefaultCommandLineSwitch kDefaultSwitches[] = {
     {cc::switches::kDisableThreadedAnimation, ""},
 #endif  // defined(OS_ANDROID)
 #endif  // BUILDFLAG(IS_CAST_AUDIO_ONLY)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
     // This is needed for now to enable the x11 Ozone platform to work with
     // current Linux/NVidia OpenGL drivers.
@@ -318,7 +318,7 @@ const DefaultCommandLineSwitch kDefaultSwitches[] = {
     {switches::kEnableHardwareOverlays, "cast"},
 #endif
 #endif
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     // It's better to start GPU process on demand. For example, for TV platforms
     // cast starts in background and can't render until TV switches to cast
     // input.
@@ -459,7 +459,7 @@ void CastBrowserMainParts::ToolkitInitialized() {
     views_delegate_ = std::make_unique<CastViewsDelegate>();
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::FilePath dir_font = GetApplicationFontsDir();
   const FcChar8 *dir_font_char8 = reinterpret_cast<const FcChar8*>(dir_font.value().data());
   if (!FcConfigAppFontAddDir(gfx::GetGlobalFontConfig(), dir_font_char8)) {
