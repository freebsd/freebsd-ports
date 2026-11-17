-- Define MAP_NORESERVE as a no-op where the platform lacks it
-- FreeBSD does not provide MAP_NORESERVE, so kaffpa fails to compile
--- lib/tools/small_block_alloc.h.orig	2026-11-16 18:54:25 UTC
+++ lib/tools/small_block_alloc.h
@@ -19,6 +19,10 @@
 #include <new>
 #include <sys/mman.h>
 
+#ifndef MAP_NORESERVE
+#define MAP_NORESERVE 0
+#endif
+
 namespace small_block_alloc {
 
 static const size_t GRANULE     = 16;
