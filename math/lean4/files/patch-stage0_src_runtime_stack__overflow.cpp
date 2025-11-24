--- stage0/src/runtime/stack_overflow.cpp.orig	2025-05-06 09:12:17 UTC
+++ stage0/src/runtime/stack_overflow.cpp
@@ -7,6 +7,10 @@ Port of the corresponding Rust code (see links below).
 Print a nicer error message on stack overflow.
 Port of the corresponding Rust code (see links below).
 */
+
+#include <pthread_np.h>
+#define pthread_getattr_np pthread_attr_get_np
+
 #ifdef LEAN_WINDOWS
 #include <windows.h>
 #else
