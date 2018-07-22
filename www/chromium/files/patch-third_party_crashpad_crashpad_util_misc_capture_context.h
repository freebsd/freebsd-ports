--- third_party/crashpad/crashpad/util/misc/capture_context.h.orig	2018-06-13 00:11:02.000000000 +0200
+++ third_party/crashpad/crashpad/util/misc/capture_context.h	2018-07-20 01:55:34.949535000 +0200
@@ -21,7 +21,7 @@
 #include <mach/mach.h>
 #elif defined(OS_WIN)
 #include <windows.h>
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <ucontext.h>
 #endif  // OS_MACOSX
 
@@ -33,7 +33,7 @@
 #endif
 #elif defined(OS_WIN)
 using NativeCPUContext = CONTEXT;
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 using NativeCPUContext = ucontext_t;
 #endif  // OS_MACOSX
 
