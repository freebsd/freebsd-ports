--- include/rude.h.orig	Mon Jun 23 17:35:23 2003
+++ include/rude.h	Mon Jun 23 17:35:42 2003
@@ -24,6 +24,7 @@
 #ifndef _RUDE_H
 #define _RUDE_H
 
+#include <sys/types.h>
 #include <netinet/in.h>  /* for struct sockaddr_in */
 #include <sys/time.h>    /* for struct timeval     */
 
