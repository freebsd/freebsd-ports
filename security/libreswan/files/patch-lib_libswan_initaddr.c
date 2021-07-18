--- lib/libswan/initaddr.c.orig	2021-04-22 15:24:33 UTC
+++ lib/libswan/initaddr.c
@@ -16,6 +16,7 @@
  */
 
 #include <string.h>
+#include <sys/socket.h>
 
 #include "ip_info.h"
 #include "ip_address.h"
