--- third_party/crashpad/crashpad/util/misc/capture_context.h.orig	2018-08-01 00:09:40.000000000 +0200
+++ third_party/crashpad/crashpad/util/misc/capture_context.h	2018-08-04 21:08:07.783574000 +0200
@@ -21,7 +21,7 @@
 #include <mach/mach.h>
 #elif defined(OS_WIN)
 #include <windows.h>
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <ucontext.h>
 #elif defined(OS_FUCHSIA)
 #include <signal.h>
@@ -35,7 +35,7 @@
 #endif
 #elif defined(OS_WIN)
 using NativeCPUContext = CONTEXT;
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 using NativeCPUContext = ucontext_t;
 #endif  // OS_MACOSX
 
