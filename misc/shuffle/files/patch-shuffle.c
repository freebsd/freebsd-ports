--- shuffle.c.orig	Wed Jun 13 22:07:36 2001
+++ shuffle.c	Wed Jun 13 22:07:36 2001
@@ -133,10 +133,11 @@
 static void
 usage()
 {
+	extern const char *__progname;
 
 	(void) fprintf(stderr,
     "Usage: %s [-f <filename>] [-n <number>] [-p <number>] [<arg> ...]\n",
-		getprogname());
+		__progname);
 	exit(1);
 }
 
