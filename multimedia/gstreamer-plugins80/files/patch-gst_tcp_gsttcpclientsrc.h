--- gst/tcp/gsttcpclientsrc.h.orig	Wed Jun 23 23:44:07 2004
+++ gst/tcp/gsttcpclientsrc.h	Wed Jun 23 23:44:26 2004
@@ -29,6 +29,8 @@
 #endif /* __cplusplus */
 
 #include <netdb.h>                        /* sockaddr_in */
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>			  /* sockaddr_in */
 #include <unistd.h>
 #include "gsttcp.h"
