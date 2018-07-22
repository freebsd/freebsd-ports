--- third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc.orig	2018-07-19 19:55:17.168592000 +0200
+++ third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc	2018-07-19 19:55:37.640206000 +0200
@@ -64,7 +64,7 @@
     "INFO",
     "USR1",
     "USR2",
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     // sed -Ene 's/^#define[[:space:]]SIG([[:alnum:]]+)[[:space:]]+[[:digit:]]{1,2}([[:space:]]|$).*/    "\1",/p'
     //     /usr/include/asm-generic/signal.h
     // and fix up by removing SIGIOT, SIGLOST, SIGUNUSED, and SIGRTMIN.
@@ -101,7 +101,7 @@
     "SYS",
 #endif
 };
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // NSIG is 64 to account for real-time signals.
 static_assert(arraysize(kSignalNames) == 32, "kSignalNames length");
 #else
