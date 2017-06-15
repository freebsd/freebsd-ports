--- secmem/secmem.c.orig	2016-04-14 14:39:51 UTC
+++ secmem/secmem.c
@@ -88,7 +88,7 @@ log_fatal(char *template, ...)
 #  define MAP_ANONYMOUS MAP_ANON
 #endif
 
-#define DEFAULT_POOLSIZE 16384
+#define DEFAULT_POOLSIZE 16384*4
 
 typedef struct memblock_struct MEMBLOCK;
 struct memblock_struct {
