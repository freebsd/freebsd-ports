--- lib/libswan/ip_info.c.orig	2021-05-21 18:51:44 UTC
+++ lib/libswan/ip_info.c
@@ -17,6 +17,8 @@
  * for more details.
  */
 
+#include <sys/socket.h>
+
 #include "ietf_constants.h"
 #include "ip_info.h"
 #include "passert.h"
