--- src/lmhosts.c.orig	Thu Feb 13 08:48:40 2003
+++ src/lmhosts.c	Thu Feb 13 08:49:05 2003
@@ -31,6 +31,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
