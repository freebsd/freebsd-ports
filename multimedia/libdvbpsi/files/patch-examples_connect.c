--- ./examples/connect.c.orig  2007-01-18 15:57:08.000000000 +0100
+++ ./examples/connect.c       2008-01-13 18:32:16.000000000 +0100
@@ -38,7 +38,9 @@
 #   include <netinet/if_ether.h>
 #endif
 #include <netdb.h>
-#include <netinet/ip.h>
+#ifndef __FreeBSD__
+#   include <netinet/ip.h>
+#endif
 #include <netinet/udp.h>
 #include <arpa/inet.h>
