--- inet.c.orig	Tue Oct 29 08:09:14 2002
+++ inet.c	Tue Oct 29 08:09:27 2002
@@ -24,6 +24,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <stdlib.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
 
