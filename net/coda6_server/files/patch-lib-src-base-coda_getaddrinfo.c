--- lib-src/base/coda_getaddrinfo.c.orig	Mon Aug 16 10:42:57 2004
+++ lib-src/base/coda_getaddrinfo.c	Mon Aug 16 10:46:09 2004
@@ -37,6 +37,10 @@
 #endif
 
 #include <sys/types.h>
+#include <sys/param.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
+#include <resolv.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
