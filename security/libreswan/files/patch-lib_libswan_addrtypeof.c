--- lib/libswan/addrtypeof.c.orig	2021-05-21 18:49:29 UTC
+++ lib/libswan/addrtypeof.c
@@ -14,6 +14,7 @@
  */
 
 #include <string.h>
+#include <sys/socket.h>
 
 #include "ip_address.h"
 #include "ip_info.h"
