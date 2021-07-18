--- lib/libswan/ip_endpoint.c.orig	2021-05-21 18:53:45 UTC
+++ lib/libswan/ip_endpoint.c
@@ -14,6 +14,8 @@
  *
  */
 
+#include <sys/socket.h>
+
 #include "jambuf.h"
 #include "ip_endpoint.h"
 #include "constants.h"		/* for memeq() */
