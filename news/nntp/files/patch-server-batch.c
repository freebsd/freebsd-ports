--- server/batch.c.orig	Fri Dec  9 03:52:44 1994
+++ server/batch.c	Mon Nov  4 05:45:49 2002
@@ -31,7 +31,9 @@
 
 /* imports */
 extern time_t time();
+#ifndef __FreeBSD__
 extern char *malloc(), *mktemp(), *index(), *rindex();
+#endif
 /* forwards */
 static char *strsave();
 #ifdef XFER_TIMEOUT
