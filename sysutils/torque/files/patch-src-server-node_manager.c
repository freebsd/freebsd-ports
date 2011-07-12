--- src/server/node_manager.c.orig	2011-06-24 13:21:21.000000000 -0500
+++ src/server/node_manager.c	2011-06-24 13:21:47.000000000 -0500
@@ -88,6 +88,7 @@
 #include <fcntl.h>
 #include <netdb.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <stdarg.h>
 #include <assert.h>
