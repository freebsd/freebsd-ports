--- pim6sd/config.c	Tue Nov 19 03:16:55 2002
+++ pim6sd/config.c	Tue Nov 19 03:15:44 2002
@@ -66,6 +66,7 @@
 #endif
 #include <net/route.h>
 #include <netinet/in.h>
+#include <sys/param.h>
 #include <netinet6/ip6_mroute.h>
 #include <netinet6/in6_var.h>
 #include <arpa/inet.h>
