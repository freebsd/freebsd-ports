--- chromecast/browser/cast_browser_main_parts.cc.orig	2022-07-22 17:30:31 UTC
+++ chromecast/browser/cast_browser_main_parts.cc
@@ -91,7 +91,7 @@
 #include "ui/base/ui_base_switches.h"
 #include "ui/gl/gl_switches.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fontconfig/fontconfig.h>
 #include <signal.h>
 #include <sys/prctl.h>
@@ -278,7 +278,7 @@ class CastViewsDelegate : public views::ViewsDelegate 
 
 #endif  // defined(USE_AURA)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 base::FilePath GetApplicationFontsDir() {
   std::unique_ptr<base::Environment> env(base::Environment::Create());
@@ -324,7 +324,7 @@ const DefaultCommandLineSwitch kDefaultSwitches[] = {
     {cc::switches::kDisableThreadedAnimation, ""},
 #endif  // BUILDFLAG(IS_ANDROID)
 #endif  // BUILDFLAG(IS_CAST_AUDIO_ONLY)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
     // This is needed for now to enable the x11 Ozone platform to work with
     // current Linux/NVidia OpenGL drivers.
@@ -512,7 +512,7 @@ void CastBrowserMainParts::ToolkitInitialized() {
     views_delegate_ = std::make_unique<CastViewsDelegate>();
 #endif  // defined(USE_AURA)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::FilePath dir_font = GetApplicationFontsDir();
   const FcChar8 *dir_font_char8 = reinterpret_cast<const FcChar8*>(dir_font.value().data());
   if (!FcConfigAppFontAddDir(gfx::GetGlobalFontConfig(), dir_font_char8)) {
