--- bjnp-io.c.orig	2009-02-28 12:08:51.000000000 -0800
+++ bjnp-io.c	2009-04-28 16:59:11.000000000 -0700
@@ -15,6 +15,8 @@
  * <to be added>
  */
 
+#include "config.h"
+
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include <sys/select.h>
