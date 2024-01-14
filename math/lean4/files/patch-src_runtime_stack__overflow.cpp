--- src/runtime/stack_overflow.cpp.orig	2023-12-21 22:11:33 UTC
+++ src/runtime/stack_overflow.cpp
@@ -20,6 +20,9 @@ Port of the corresponding Rust code (see links below).
 #include <lean/lean.h>
 #include "runtime/stack_overflow.h"
 
+#include <pthread_np.h>
+#define pthread_getattr_np pthread_attr_get_np
+
 namespace lean {
 // stack guard of the main thread
 static stack_guard * g_stack_guard;
