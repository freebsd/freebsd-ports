--- src/metalog.c.orig	2012-08-18 16:19:00 UTC
+++ src/metalog.c
@@ -6,6 +6,9 @@
 #ifdef WITH_DMALLOC
 # include <dmalloc.h>
 #endif
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define fflush_unlocked fflush
+#endif
 
 static int spawn_recursion = 0;
 static int dolog_queue[2];
