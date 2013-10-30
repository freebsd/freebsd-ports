--- ./src/metalog.c.orig	2013-10-29 09:50:12.000000000 -0400
+++ ./src/metalog.c	2013-10-29 09:52:28.000000000 -0400
@@ -6,6 +6,9 @@
 #ifdef WITH_DMALLOC
 # include <dmalloc.h>
 #endif
+#if defined(__FreeBSD__)
+#define fflush_unlocked fflush
+#endif
 
 static int spawn_recursion = 0;
 static int dolog_queue[2];
