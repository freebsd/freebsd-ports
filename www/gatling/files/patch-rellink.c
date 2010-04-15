--- rellink.c.orig	2010-04-15 22:07:47.000000000 +0200
+++ rellink.c	2010-04-15 22:07:55.000000000 +0200
@@ -17,6 +17,7 @@
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <utime.h>
+#include <string.h>
 #include "havealloca.h"
 
 static int canonicalize(stralloc* url,const char* baseurl) {
