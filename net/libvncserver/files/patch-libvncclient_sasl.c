--- libvncclient/sasl.c.orig	2019-01-30 04:13:40 UTC
+++ libvncclient/sasl.c
@@ -55,6 +55,8 @@
 #endif /* LIBVNCSERVER_HAVE_WS2TCPIP_H */
 #else /* WIN32 */
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #endif /* WIN32 */
 
 #include "sasl.h"
