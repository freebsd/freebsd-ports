--- lib/libswan/ip_address.c.orig	2021-05-21 18:51:10 UTC
+++ lib/libswan/ip_address.c
@@ -16,6 +16,8 @@
  * License for more details.
  */
 
+#include <sys/socket.h>
+
 #include "jambuf.h"
 #include "ip_address.h"
 #include "lswlog.h"		/* for dbg() */
