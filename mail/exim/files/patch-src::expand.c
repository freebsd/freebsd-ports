--- src/expand.c.orig	Mon Sep 22 10:29:56 2003
+++ src/expand.c	Tue Oct 28 15:39:43 2003
@@ -4114,6 +4114,7 @@
 
 if (s == NULL) return -1;
 
+errno = 0;
 value = strtol(CS s, CSS &endptr, 0);
 
 if (endptr == s)
