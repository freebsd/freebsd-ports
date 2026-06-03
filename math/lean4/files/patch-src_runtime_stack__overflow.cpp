--- src/runtime/stack_overflow.cpp.orig	2026-03-27 12:45:03 UTC
+++ src/runtime/stack_overflow.cpp
@@ -21,6 +21,11 @@ Port of the corresponding Rust code (see links below).
 #include <initializer_list>
 #include "runtime/stack_overflow.h"
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#define pthread_getattr_np pthread_attr_get_np
+#endif
+
 namespace lean {
 // stack guard of the main thread
 static stack_guard * g_stack_guard;
@@ -64,8 +69,18 @@ bool is_within_stack_guard(void * addr) {
 #endif
     // close enough; the actual guard might be bigger, but it's unlikely a Lean function will have stack frames that big
     size_t guardsize = static_cast<size_t>(sysconf(_SC_PAGESIZE));
+#if defined(__FreeBSD__)
+    // On FreeBSD the guard page position depends on how the thread was created:
+    // - Main thread with ulimit: guard is below stackaddr (Linux-style, linux_check)
+    // - Spawned threads with explicit stacksize: guard is the first page of the
+    //   region starting at stackaddr (freebsd_check)
+    // Accept either convention.
+    return (stackaddr - guardsize <= addr && addr < stackaddr) ||
+           (stackaddr <= addr && addr < stackaddr + guardsize);
+#else
     // the stack guard is *below* the stack
     return stackaddr - guardsize <= addr && addr < stackaddr;
+#endif
 }
 
 extern "C" LEAN_EXPORT void segv_handler(int signum, siginfo_t * info, void *) {
