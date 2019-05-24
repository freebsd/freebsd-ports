--- chromecast/browser/cast_browser_main_parts.cc.orig	2019-04-30 22:22:40 UTC
+++ chromecast/browser/cast_browser_main_parts.cc
@@ -67,7 +67,7 @@
 #include "ui/compositor/compositor_switches.h"
 #include "ui/gl/gl_switches.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fontconfig/fontconfig.h>
 #include <signal.h>
 #include <sys/prctl.h>
@@ -245,7 +245,7 @@ const DefaultCommandLineSwitch kDefaultSwitches[] = {
     {cc::switches::kDisableThreadedAnimation, ""},
 #endif  // defined(OS_ANDROID)
 #endif  // BUILDFLAG(IS_CAST_AUDIO_ONLY)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
     // This is needed for now to enable the x11 Ozone platform to work with
     // current Linux/NVidia OpenGL drivers.
@@ -255,7 +255,7 @@ const DefaultCommandLineSwitch kDefaultSwitches[] = {
     {switches::kEnableHardwareOverlays, "cast"},
 #endif
 #endif
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     // It's better to start GPU process on demand. For example, for TV platforms
     // cast starts in background and can't render until TV switches to cast
     // input.
@@ -394,7 +394,7 @@ void CastBrowserMainParts::PostMainMessageLoopStart() 
 }
 
 void CastBrowserMainParts::ToolkitInitialized() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Without this call, the FontConfig library gets implicitly initialized
   // on the first call to FontConfig. Since it's not safe to initialize it
   // concurrently from multiple threads, we explicitly initialize it here
