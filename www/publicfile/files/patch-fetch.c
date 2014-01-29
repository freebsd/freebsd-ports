--- fetch.c.orig	1999-11-08 23:23:46.000000000 -0800
+++ fetch.c	2014-01-29 15:19:43.000000000 -0800
@@ -82,7 +82,7 @@
   substdio_puts(&ss,"\r\n");
 }
 
-static int doit(char *fn,int fddata,int fdfile,int how)
+static void doit(char *fn,int fddata,int fdfile,int how)
 {
   DIR *dir;
   direntry *d;
@@ -122,7 +122,7 @@
       for (;;) {
 	r = read(fdfile,inbuf,sizeof inbuf);
 	if (r == -1) {
-	  if (errno = error_intr) continue;
+	  if (errno == error_intr) continue;
 	  _exit(23);
 	}
 	if (r == 0)
