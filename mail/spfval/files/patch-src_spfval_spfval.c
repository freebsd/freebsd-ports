--- src/spfval/spfval.c.orig	Mon Jul 25 07:46:21 2005
+++ src/spfval/spfval.c	Mon Jul 25 07:46:30 2005
@@ -44,6 +44,7 @@
 #include <stdio.h>         /* printf */
 #include <stdlib.h>        /* malloc / free */
 #include <string.h>        /* printf */
+#include <sys/types.h>
 #include <sys/socket.h>    /* inet_ntoa */
 #include <netinet/in.h>    /* inet_ntoa / ntohl */
 #include <arpa/inet.h>     /* inet_ntoa */
