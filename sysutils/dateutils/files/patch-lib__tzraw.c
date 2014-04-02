--- ./lib/tzraw.c.orig	2014-01-29 10:08:23.000000000 -0500
+++ ./lib/tzraw.c	2014-03-27 23:53:01.000000000 -0400
@@ -70,9 +70,14 @@
 /* me own header, innit */
 #include "tzraw.h"
 
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
+
 
 #if defined TZDIR
 static const char tzdir[] = TZDIR;
