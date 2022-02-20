--- third_party/crashpad/crashpad/util/misc/capture_context.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/crashpad/crashpad/util/misc/capture_context.h
@@ -21,7 +21,8 @@
 #include <mach/mach.h>
 #elif defined(OS_WIN)
 #include <windows.h>
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+    defined(OS_FREEBSD)
 #include <ucontext.h>
 #elif defined(OS_FUCHSIA)
 #include <signal.h>
@@ -38,7 +39,7 @@ using NativeCPUContext = arm_unified_thread_state;
 #elif defined(OS_WIN)
 using NativeCPUContext = CONTEXT;
 #elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
 using NativeCPUContext = ucontext_t;
 #endif  // OS_APPLE
 
