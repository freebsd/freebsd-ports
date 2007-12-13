--- src/utils.c.orig	Mon Sep  3 21:54:48 2007
+++ src/utils.c	Wed Nov 14 12:26:19 2007
@@ -23,7 +23,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
-#include <values.h>
+#include <limits.h>
 #include <time.h>
 #include <signal.h>
 #include <string.h>
@@ -208,8 +208,8 @@
     */
    j=0;
    k=0;
-   t1=MAXINT;
-   t2=MAXINT;
+   t1=INT_MAX;
+   t2=INT_MAX;
    for (i=0; i<DNS_CACHE_SIZE; i++) {
       if (dns_cache[i].hostname[0]=='\0') break;
       if ((dns_cache[i].expires_timestamp < t1) &&
