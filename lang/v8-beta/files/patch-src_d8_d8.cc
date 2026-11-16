--- src/d8/d8.cc.orig	2026-11-15 17:31:12 UTC
+++ src/d8/d8.cc
@@ -111,6 +111,11 @@
 #include <signal.h>
 #endif  // V8_OS_POSIX
 
+#if V8_OS_FREEBSD
+#include <sys/procctl.h>
+#include <unistd.h>
+#endif  // V8_OS_FREEBSD
+
 // gn check complains when not using the v8_fuzzilli or v8_redline arg since the
 // public dep. is added conditionally
 #if defined(V8_REDLINE)
@@ -8418,7 +8423,17 @@ int Shell::Main(int argc, char* argv[]) {
 #if defined(V8_ENABLE_PARTITION_ALLOC)
 #if PA_BUILDFLAG(ENABLE_USER_SPACE_ZERO_SEGMENT) && !defined(V8_OS_ANDROID) && \
     !defined(V8_OS_WIN)
+#if V8_OS_FREEBSD
+  // Without ASLR, FreeBSD loads position-independent executables below 4GB,
+  // so the zero segment can not be reserved.
+  int aslr_status = 0;
+  if (procctl(P_PID, getpid(), PROC_ASLR_STATUS, &aslr_status) == 0 &&
+      (aslr_status & PROC_ASLR_ACTIVE) != 0) {
+    i::v8_flags.sandbox_prohibit_insecure_mode.Set(true);
+  }
+#else
   i::v8_flags.sandbox_prohibit_insecure_mode.Set(true);
+#endif  // V8_OS_FREEBSD
 #endif  // PA_BUILDFLAG(ENABLE_USER_SPACE_ZERO_SEGMENT) &&
         // !defined(V8_OS_ANDROID) && !defined(V8_OS_WIN)
 #endif  // defined(V8_ENABLE_PARTITION_ALLOC)
