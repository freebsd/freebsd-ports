--- ./src/usyslog.c.orig	2012-09-11 00:06:32.000000000 +0200
+++ ./src/usyslog.c	2013-07-24 16:56:29.401473882 +0200
@@ -20,7 +20,9 @@
 #include <string.h>
 #include <stdlib.h>
 #include <errno.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <pthread.h>
 #include <stdarg.h>
 
