--- src/d8/d8.cc.orig	2026-11-02 14:07:25 UTC
+++ src/d8/d8.cc
@@ -110,6 +110,11 @@
 #include <signal.h>
 #endif  // V8_OS_POSIX
 
+#if V8_OS_FREEBSD
+#include <sys/procctl.h>
+#include <unistd.h>
+#endif  // V8_OS_FREEBSD
+
 #ifdef V8_FUZZILLI
 // gn check complains when not using the v8_fuzzilli arg since the public dep.
 // is added conditionally
@@ -8188,7 +8193,17 @@
   // user space zero segment.
 #if defined(V8_ENABLE_PARTITION_ALLOC)
 #if PA_BUILDFLAG(ENABLE_USER_SPACE_ZERO_SEGMENT) && !defined(V8_OS_ANDROID)
+#if V8_OS_FREEBSD
+  // Without ASLR, FreeBSD loads position-independent executables below 4GB,
+  // so the zero segment can not be reserved.
+  int aslr_status = 0;
+  if (procctl(P_PID, getpid(), PROC_ASLR_STATUS, &aslr_status) == 0 &&
+      (aslr_status & PROC_ASLR_ACTIVE) != 0) {
+    i::v8_flags.sandbox_prohibit_insecure_mode = true;
+  }
+#else
   i::v8_flags.sandbox_prohibit_insecure_mode = true;
+#endif  // V8_OS_FREEBSD
 #endif  // PA_BUILDFLAG(ENABLE_USER_SPACE_ZERO_SEGMENT) &&
         // !defined(V8_OS_ANDROID)
 #endif  // defined(V8_ENABLE_PARTITION_ALLOC)
