--- chromecast/browser/cast_browser_main_parts.cc.orig	2019-01-10 01:22:24.493908000 +0100
+++ chromecast/browser/cast_browser_main_parts.cc	2019-01-10 01:23:14.020775000 +0100
@@ -73,7 +73,7 @@
 #include "ui/compositor/compositor_switches.h"
 #include "ui/gl/gl_switches.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fontconfig/fontconfig.h>
 #include <signal.h>
 #include <sys/prctl.h>
@@ -246,7 +246,7 @@
     {cc::switches::kDisableThreadedAnimation, ""},
 #endif  // defined(OS_ANDROID)
 #endif  // BUILDFLAG(IS_CAST_AUDIO_ONLY)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
     // This is needed for now to enable the x11 Ozone platform to work with
     // current Linux/NVidia OpenGL drivers.
@@ -393,7 +393,7 @@
 }
 
 void CastBrowserMainParts::ToolkitInitialized() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Without this call, the FontConfig library gets implicitly initialized
   // on the first call to FontConfig. Since it's not safe to initialize it
   // concurrently from multiple threads, we explicitly initialize it here
