--- panel-plugin/http_client.h.orig	Mon Apr 19 16:15:44 2004
+++ panel-plugin/http_client.h	Mon Jun  7 15:52:19 2004
@@ -1,3 +1,4 @@
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
 #include <netinet/in.h>
