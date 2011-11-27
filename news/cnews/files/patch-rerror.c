--- libcnews/rerror.c.orig	1994-09-19 05:26:08.000000000 +0200
+++ libcnews/rerror.c	2011-05-12 15:41:43.000000000 +0200
@@ -19,7 +19,7 @@
 
 /* common log reporting */
 static
-log(stream, art, code, fmt, arg, sverrno)
+cnews_log(stream, art, code, fmt, arg, sverrno)
 register FILE *stream;
 register struct article *art;
 int code;
@@ -60,7 +60,7 @@
 int code;
 char *fmt, *arg;
 {
-	log(stdout, art, code, fmt, arg, 0);
+	cnews_log(stdout, art, code, fmt, arg, 0);
 }
 
 /*
@@ -72,7 +72,7 @@
 int code;
 char *fmt, *arg;
 {
-	log(stdout, art, code, fmt, arg, 0);
+	cnews_log(stdout, art, code, fmt, arg, 0);
 	if (art != NULL)
 		art->a_status |= ST_REFUSED;
 }
@@ -86,7 +86,7 @@
 int code;
 char *fmt, *arg;
 {
-	log(stderr, art, code, fmt, arg, errno);
+	cnews_log(stderr, art, code, fmt, arg, errno);
 	if (art != NULL)
 		art->a_status |= ST_NEEDATTN|ST_DROPPED;
 }
