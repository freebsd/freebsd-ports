-- workaround for https://github.com/leanprover/lean4/issues/14136
-- Compilation fails: error: 'free_sized' is missing exception specification 'throw()'
-- on FreeBSD 16

--- stage0/src/runtime/object.cpp.orig	2026-06-22 01:22:24 UTC
+++ stage0/src/runtime/object.cpp
@@ -61,7 +61,7 @@ __attribute__((nothrow))
 // `__attribute__((nothrow))` to be present or `noexcept`.
 __attribute__((nothrow))
 #endif
-__attribute__((weak)) void free_sized(void *ptr, size_t) {
+__attribute__((weak)) void free_sized(void *ptr, size_t) throw() {
     free(ptr);
 }
 #endif
