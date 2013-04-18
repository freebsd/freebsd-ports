--- ./xpipes.c.orig	2013-04-18 09:50:44.000000000 -0400
+++ ./xpipes.c	2013-04-18 09:54:21.000000000 -0400
@@ -37,7 +37,11 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#ifdef linux
 #include <linux/limits.h>
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 #include <pthread.h>
 #include <unistd.h>
 
