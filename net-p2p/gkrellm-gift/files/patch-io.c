--- src/io.c.orig	Sat Dec 20 10:42:39 2003
+++ src/io.c	Wed May  5 00:58:19 2004
@@ -16,6 +16,7 @@
  *
  */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include <netdb.h>
