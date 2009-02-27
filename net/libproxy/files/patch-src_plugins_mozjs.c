--- src/plugins/mozjs.c.orig	2009-02-27 00:18:46.000000000 -0500
+++ src/plugins/mozjs.c	2009-02-27 00:18:56.000000000 -0500
@@ -23,6 +23,7 @@
 #include <sys/socket.h>
 #include <netdb.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #define __USE_BSD
 #include <unistd.h>
 
