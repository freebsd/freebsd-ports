--- server/group.c.orig	Sat Dec  3 22:54:51 1994
+++ server/group.c	Mon Nov  4 05:43:39 2002
@@ -11,7 +11,9 @@
 extern void close_xfiles();
 #endif
 
+#ifndef __FreeBSD__
 extern char *malloc();
+#endif
 
 /*
  * GROUP newsgroup
