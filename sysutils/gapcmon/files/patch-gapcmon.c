--- src/gapcmon.c.orig	Wed Oct  3 19:53:05 2007
+++ src/gapcmon.c	Wed Oct  3 19:53:32 2007
@@ -74,6 +74,7 @@
 #include <unistd.h>             /* close() */
 #include <sys/types.h>          /* socket() */
 #include <sys/socket.h>         /* socket() */
+#include <netinet/in.h>
 #include <arpa/inet.h>          /* ntohs() */
 #include <netdb.h>              /* gethostbyname() */
 #include <errno.h>
