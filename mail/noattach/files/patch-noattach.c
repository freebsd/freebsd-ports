--- noattach.c.orig	Thu Aug 21 15:52:48 2003
+++ noattach.c	Tue Oct 12 18:02:32 2004
@@ -54,7 +54,9 @@
 #define BUFFER_SIZE (MILTER_CHUNK_SIZE+OVERLAP_SIZE)
 
 #ifndef true
+#ifndef __bool_true_false_are_defined
 typedef int     bool;
+#endif /* ! __bool_true_false_are_defined */
 #define false  0
 #define true   1
 #endif				/* ! true */
