-- Do not call sbrk(), it is not available in libc on recent FreeBSD, which
-- breaks linking of the shared library (undefined reference: sbrk).

--- SRC/util.c.orig	2026-11-08 18:23:10 UTC
+++ SRC/util.c
@@ -304,7 +304,7 @@ int_t check_mem_leak(char *where)
 
 int_t check_mem_leak(char *where)
 {
-#ifdef unix
+#if defined(unix) && !defined(__FreeBSD__)
     void *addr;
     addr = (void *)sbrk(0);
     printf("\tsbrk(0) %s: addr = %ld\n", where, (size_t) addr);
