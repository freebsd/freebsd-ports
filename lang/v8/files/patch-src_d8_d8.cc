--- src/d8/d8.cc.orig	2026-10-05 07:40:58 UTC
+++ src/d8/d8.cc
@@ -109,6 +109,11 @@
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
@@ -8032,7 +8037,17 @@ int Shell::Main(int argc, char* argv[]) {
 
   // TODO(40925855): Enable this more broadly outside of d8.
 #if defined(PA_ENABLE_USER_SPACE_ZERO_SEGMENT)
+#if V8_OS_FREEBSD
+  // Without ASLR, FreeBSD loads position-independent executables below 4GB,
+  // so the first 4GB of the address space can not be reserved.
+  int aslr_status = 0;
+  if (procctl(P_PID, getpid(), PROC_ASLR_STATUS, &aslr_status) == 0 &&
+      (aslr_status & PROC_ASLR_ACTIVE) != 0) {
+    i::v8_flags.sandbox_prohibit_insecure_mode = true;
+  }
+#else
   i::v8_flags.sandbox_prohibit_insecure_mode = true;
+#endif  // V8_OS_FREEBSD
 #endif
 
   if (!v8::Shell::SetOptions(argc, argv)) return 1;
