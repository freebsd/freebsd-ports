--- chromecast/browser/cast_browser_main_parts.cc.orig	2017-07-25 21:04:53.000000000 +0200
+++ chromecast/browser/cast_browser_main_parts.cc	2017-08-02 00:26:41.838446000 +0200
@@ -70,7 +70,7 @@
 #include <signal.h>
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fontconfig/fontconfig.h>
 #endif
 
@@ -237,7 +237,7 @@
     {switches::kSkipGpuDataLoading, ""},
 #endif  // defined(OS_ANDROID)
 #endif  // BUILDFLAG(IS_CAST_AUDIO_ONLY)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
     // This is needed for now to enable the x11 Ozone platform to work with
     // current Linux/NVidia OpenGL drivers.
@@ -247,7 +247,7 @@
     {switches::kEnableHardwareOverlays, "cast"},
 #endif
 #endif
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     // Needed so that our call to GpuDataManager::SetGLStrings doesn't race
     // against GPU process creation (which is otherwise triggered from
     // BrowserThreadsStarted).  The GPU process will be created as soon as a
@@ -382,7 +382,7 @@
 }
 
 void CastBrowserMainParts::ToolkitInitialized() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Without this call, the FontConfig library gets implicitly initialized
   // on the first call to FontConfig. Since it's not safe to initialize it
   // concurrently from multiple threads, we explicitly initialize it here
