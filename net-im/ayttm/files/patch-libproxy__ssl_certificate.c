--- libproxy/ssl_certificate.c.orig
+++ libproxy/ssl_certificate.c
@@ -24,6 +24,9 @@
 #include <glib.h>
 #include "ssl_certificate.h"
 #ifndef __MINGW32__
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>
 #else
 #include <winsock2.h>
