--- src/runtime/stack_overflow.cpp.orig	2025-11-18 02:29:21 UTC
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
