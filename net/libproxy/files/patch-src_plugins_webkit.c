--- src/plugins/webkit.c.orig	2009-02-27 00:22:39.000000000 -0500
+++ src/plugins/webkit.c	2009-02-27 00:22:50.000000000 -0500
@@ -21,6 +21,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
 #define __USE_BSD
