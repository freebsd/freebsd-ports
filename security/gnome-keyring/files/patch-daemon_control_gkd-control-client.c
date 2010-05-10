--- daemon/control/gkd-control-client.c.orig	2009-12-21 18:43:16.000000000 -0500
+++ daemon/control/gkd-control-client.c	2009-12-21 18:44:17.000000000 -0500
@@ -31,6 +31,8 @@
 #include <errno.h>
 #include <fcntl.h>
 
+#include <string.h>
+#include <sys/stat.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/un.h>
