--- mem.c.orig	Wed Mar  3 22:11:23 1993
+++ mem.c	Sat Oct  7 20:16:25 2006
@@ -19,6 +19,10 @@
 extern char *sbrk();
 #endif
 
+#ifdef MYMALLOC
+STATIC void addtoheap();
+#endif
+
 /* privates */
 STATIC void nomem();
 static link *Lcache;
@@ -105,8 +109,6 @@
 	long size;
 {
 #ifdef MYMALLOC
-	STATIC void addtoheap();
-
 	addtoheap((char *) t, size * sizeof(node *));
 #else
 	free((char *) t);
