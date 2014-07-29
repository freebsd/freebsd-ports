--- configfile.c.orig	Fri Aug  9 15:24:23 2002
+++ configfile.c	Mon Jul 28 11:22:34 2003
@@ -23,6 +23,7 @@
 #include <string.h>
 #include <strings.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
