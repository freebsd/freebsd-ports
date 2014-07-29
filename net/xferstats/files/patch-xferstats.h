--- xferstats.x	Thu Jan 11 19:35:18 2001
+++ xferstats.h	Thu Jan 11 19:35:52 2001
@@ -39,6 +39,7 @@
 
 /* glibc's malloc is so damn efficient, chunks actually slow it down.  so only
  * use g_mem_chunks on non-glibc systems */
+#define __GLIBC__
 #ifdef __GLIBC__
 #  define G_MEM_CHUNK_ALLOC(bar) g_malloc(bar)
 #  define G_MEM_CHUNK_ALLOC0(bar) g_malloc0(bar)
