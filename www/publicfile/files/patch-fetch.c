--- fetch.c.orig	1999-11-09 07:23:46 UTC
+++ fetch.c
@@ -82,7 +82,7 @@ static void list(char *fn,int flaglong)
   substdio_puts(&ss,"\r\n");
 }
 
-static int doit(char *fn,int fddata,int fdfile,int how)
+static void doit(char *fn,int fddata,int fdfile,int how)
 {
   DIR *dir;
   direntry *d;
@@ -122,7 +122,7 @@ static int doit(char *fn,int fddata,int fdfile,int how
       for (;;) {
 	r = read(fdfile,inbuf,sizeof inbuf);
 	if (r == -1) {
-	  if (errno = error_intr) continue;
+	  if (errno == error_intr) continue;
 	  _exit(23);
 	}
 	if (r == 0)
