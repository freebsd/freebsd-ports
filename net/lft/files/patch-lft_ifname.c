--- lft_ifname.c.orig	Wed Mar  5 16:16:49 2003
+++ lft_ifname.c	Wed Mar  5 16:17:05 2003
@@ -19,6 +19,7 @@
 #ifndef linux
 #include <sys/sockio.h>
 #endif
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
 #include <net/if.h>
