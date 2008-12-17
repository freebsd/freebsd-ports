--- bgpd/util.c	2008-03-18 15:24:06.000000000 +0100
+++ bgpd/util.c	2008-03-18 13:27:29.000000000 +0100
@@ -18,6 +18,7 @@
  */
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/limits.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
