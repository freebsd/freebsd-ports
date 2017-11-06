--- chromecast/browser/cast_browser_main_parts.cc.orig	2017-04-19 19:06:32 UTC
+++ chromecast/browser/cast_browser_main_parts.cc
@@ -70,7 +70,7 @@
 #include <signal.h>
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fontconfig/fontconfig.h>
 #endif
 
@@ -229,7 +229,7 @@ DefaultCommandLineSwitch g_default_switc
 #if BUILDFLAG(IS_CAST_AUDIO_ONLY)
   { switches::kDisableGpu, "" },
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
   // This is needed for now to enable the x11 Ozone platform to work with
   // current Linux/NVidia OpenGL drivers.
@@ -371,7 +371,7 @@ void CastBrowserMainParts::PostMainMessa
 }
 
 void CastBrowserMainParts::ToolkitInitialized() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Without this call, the FontConfig library gets implicitly initialized
   // on the first call to FontConfig. Since it's not safe to initialize it
   // concurrently from multiple threads, we explicitly initialize it here
