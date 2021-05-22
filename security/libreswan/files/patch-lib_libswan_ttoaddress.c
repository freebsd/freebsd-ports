--- lib/libswan/ttoaddress.c.orig	2021-05-21 18:49:01 UTC
+++ lib/libswan/ttoaddress.c
@@ -18,6 +18,7 @@
 
 #include <string.h>
 #include <netdb.h>		/* for gethostbyname2() */
+#include <sys/socket.h>
 
 #include "ip_address.h"
 #include "ip_info.h"
