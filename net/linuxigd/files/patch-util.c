--- util.c.orig	Sat Jun 16 09:29:31 2007
+++ util.c	Sat Jun 16 09:29:38 2007
@@ -3,7 +3,8 @@
 #include <stdarg.h>
 #include <syslog.h>
 #include <arpa/inet.h>
-#include <linux/sockios.h>
+#include <sys/sockio.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <netinet/in.h>
 #include <sys/ioctl.h>
