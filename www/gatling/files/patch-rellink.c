--- rellink.c.orig	2009-04-10 18:15:33.000000000 +0200
+++ rellink.c	2009-04-10 18:15:46.000000000 +0200
@@ -17,6 +17,7 @@
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <utime.h>
+#include <string.h>
 
 static int canonicalize(stralloc* url,const char* baseurl) {
   /* for the comments, assume baseurl is "http://www.fefe.de/x/y.html" */
