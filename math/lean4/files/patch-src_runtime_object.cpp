-- fix breakage caused by strict matching of the throw() attribute in FreeBSD 16.0

--- src/runtime/object.cpp.orig	2026-06-21 11:16:11 UTC
+++ src/runtime/object.cpp
@@ -22,6 +22,8 @@ Author: Leonardo de Moura
 #include "runtime/io.h"
 #include "runtime/hash.h"
 
+#include <sys/param.h>
+
 #if defined(__GLIBC__) || defined(__APPLE__)
     #define LEAN_SUPPORTS_BACKTRACE 1
 #else
@@ -61,7 +63,11 @@ __attribute__((nothrow))
 // `__attribute__((nothrow))` to be present or `noexcept`.
 __attribute__((nothrow))
 #endif
+#if !defined(__FreeBSD__) || __FreeBSD_version < 1600000
 __attribute__((weak)) void free_sized(void *ptr, size_t) {
+#else
+__attribute__((weak)) void free_sized(void *ptr, size_t) throw() {
+#endif
     free(ptr);
 }
 #endif
