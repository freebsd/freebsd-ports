--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/capture_context.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/capture_context.h
@@ -21,7 +21,7 @@
 #include <mach/mach.h>
 #elif defined(OS_WIN)
 #include <windows.h>
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <ucontext.h>
 #elif defined(OS_FUCHSIA)
 #include <signal.h>
@@ -35,7 +35,7 @@ using NativeCPUContext = x86_thread_state;
 #endif
 #elif defined(OS_WIN)
 using NativeCPUContext = CONTEXT;
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 using NativeCPUContext = ucontext_t;
 #endif  // OS_MACOSX
 
