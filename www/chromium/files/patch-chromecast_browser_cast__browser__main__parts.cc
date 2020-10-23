--- chromecast/browser/cast_browser_main_parts.cc.orig	2020-09-08 19:14:03 UTC
+++ chromecast/browser/cast_browser_main_parts.cc
@@ -75,7 +75,7 @@
 #include "ui/base/ui_base_switches.h"
 #include "ui/gl/gl_switches.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fontconfig/fontconfig.h>
 #include <signal.h>
 #include <sys/prctl.h>
@@ -130,7 +130,7 @@
 #include "extensions/browser/extension_prefs.h"  // nogncheck
 #endif
 
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
 #include "chromecast/browser/exo/wayland_server_controller.h"
 #endif
 
@@ -272,7 +272,7 @@ class CastViewsDelegate : public views::ViewsDelegate 
 
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 base::FilePath GetApplicationFontsDir() {
   std::unique_ptr<base::Environment> env(base::Environment::Create());
@@ -288,7 +288,7 @@ base::FilePath GetApplicationFontsDir() {
   }
 }
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace
 
@@ -317,7 +317,7 @@ const DefaultCommandLineSwitch kDefaultSwitches[] = {
     {cc::switches::kDisableThreadedAnimation, ""},
 #endif  // defined(OS_ANDROID)
 #endif  // BUILDFLAG(IS_CAST_AUDIO_ONLY)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
     // This is needed for now to enable the x11 Ozone platform to work with
     // current Linux/NVidia OpenGL drivers.
@@ -327,7 +327,7 @@ const DefaultCommandLineSwitch kDefaultSwitches[] = {
     {switches::kEnableHardwareOverlays, "cast"},
 #endif
 #endif
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(USE_CHROMEOS_MEDIA_ACCELERATION)
     // Force disable new video decoder, since it uses slice H.264, which is
     // not currently supported on Linux-based Cast devices.
@@ -484,7 +484,7 @@ void CastBrowserMainParts::ToolkitInitialized() {
     views_delegate_ = std::make_unique<CastViewsDelegate>();
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::FilePath dir_font = GetApplicationFontsDir();
   const FcChar8 *dir_font_char8 = reinterpret_cast<const FcChar8*>(dir_font.value().data());
   if (!FcConfigAppFontAddDir(gfx::GetGlobalFontConfig(), dir_font_char8)) {
@@ -666,7 +666,7 @@ void CastBrowserMainParts::PreMainMessageLoopRun() {
       cast_browser_process_->browser_context());
 #endif
 
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
   wayland_server_controller_ =
       std::make_unique<WaylandServerController>(window_manager_.get());
 #endif
@@ -748,7 +748,7 @@ bool CastBrowserMainParts::MainMessageLoopRun(int* res
 }
 
 void CastBrowserMainParts::PostMainMessageLoopRun() {
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
   wayland_server_controller_.reset();
 #endif
 #if BUILDFLAG(ENABLE_CHROMECAST_EXTENSIONS)
