--- ./src/prchunk.c.orig	2014-01-29 10:08:23.000000000 -0500
+++ ./src/prchunk.c	2014-03-27 23:53:01.000000000 -0400
@@ -61,9 +61,13 @@
 #define MAX_NLINES	(16384)
 #define MAX_LLEN	(1024)
 
-#if !defined MAP_ANONYMOUS && defined MAP_ANON
-# define MAP_ANONYMOUS	(MAP_ANON)
-#endif	/* MAP_ANON->MAP_ANONYMOUS */
+#ifndef MAP_ANONYMOUS
+#define MAP_ANONYMOUS 0x1000
+#endif
+
+#ifndef MAP_ANON
+#define MAP_ANON 0x1000
+#endif
 
 #if defined __INTEL_COMPILER
 # pragma warning(disable: 981)
