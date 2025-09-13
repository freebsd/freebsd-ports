--- third_party/crashpad/crashpad/util/misc/capture_context.h.orig	2025-09-11 13:19:19 UTC
+++ third_party/crashpad/crashpad/util/misc/capture_context.h
@@ -21,8 +21,11 @@
 #include <mach/mach.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
+      BUILDFLAG(IS_FREEBSD)
 #include <ucontext.h>
+#elif BUILDFLAG(IS_OPENBSD)
+#include <sys/signal.h>
 #endif  // BUILDFLAG(IS_APPLE)
 
 namespace crashpad {
@@ -35,7 +38,8 @@ using NativeCPUContext = arm_unified_thread_state;
 #endif
 #elif BUILDFLAG(IS_WIN)
 using NativeCPUContext = CONTEXT;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
+      BUILDFLAG(IS_BSD)
 using NativeCPUContext = ucontext_t;
 #endif  // BUILDFLAG(IS_APPLE)
 
