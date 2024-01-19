--- stage0/src/runtime/stack_overflow.cpp.orig	2023-12-21 22:11:33 UTC
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
@@ -19,6 +23,7 @@ Port of the corresponding Rust code (see links below).
 #include <cstring>
 #include <lean/lean.h>
 #include "runtime/stack_overflow.h"
+
 
 namespace lean {
 // stack guard of the main thread
