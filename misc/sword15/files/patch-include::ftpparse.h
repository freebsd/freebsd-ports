--- include/ftpparse.h.orig	Tue Aug 17 10:49:11 2004
+++ include/ftpparse.h	Tue Aug 17 10:49:24 2004
@@ -1,7 +1,6 @@
 #ifndef FTPPARSE_H
 #define FTPPARSE_H
 
-#include <time.h>
 
 /*
 ftpparse(&fp,buf,len) tries to parse one line of LIST output.
@@ -25,7 +24,7 @@
   int sizetype;
   long size; /* number of octets */
   int mtimetype;
-  time_t mtime; /* modification time */
+  long mtime; /* modification time */
   int idtype;
   char *id; /* not necessarily 0-terminated */
   int idlen;
