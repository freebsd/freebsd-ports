--- lib-src/base/coda_getaddrinfo.c.orig	2007-07-20 21:34:55 UTC
+++ lib-src/base/coda_getaddrinfo.c
@@ -37,6 +37,10 @@ Coda are listed in the file CREDITS.
 #endif
 
 #include <sys/types.h>
+#include <sys/param.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
+#include <resolv.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
