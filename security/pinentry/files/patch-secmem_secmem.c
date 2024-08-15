--- secmem/secmem.c.orig	2024-02-26 14:24:12 UTC
+++ secmem/secmem.c
@@ -84,7 +84,7 @@ log_fatal(char *template, ...)
 #  define MAP_ANONYMOUS MAP_ANON
 #endif
 
-#define DEFAULT_POOLSIZE 16384
+#define DEFAULT_POOLSIZE 16384*4
 
 typedef struct memblock_struct MEMBLOCK;
 struct memblock_struct {
