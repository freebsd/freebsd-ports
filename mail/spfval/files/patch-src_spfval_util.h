--- src/spfval/util.h.orig	Mon Jul 25 07:43:56 2005
+++ src/spfval/util.h	Mon Jul 25 07:44:25 2005
@@ -45,6 +45,7 @@
 #define _UTIL_H 1
 
 #include <stdlib.h>       /* malloc / free */
+#include <sys/types.h>
 #include <netinet/in.h>   /* in_addr struct fBSD */
 #include <arpa/inet.h>    /* in_addr struct */
 
