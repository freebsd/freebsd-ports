--- visualization/minilcd/sockets.c.orig	Wed Jan 21 13:08:34 2004
+++ visualization/minilcd/sockets.c	Sun Nov 21 18:27:07 2004
@@ -2,9 +2,9 @@
 #include <stdio.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
-#include <sys/types.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
