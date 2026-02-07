--- networking/nslookup.c.orig	2021-01-01 13:30:02 UTC
+++ networking/nslookup.c
@@ -34,6 +34,9 @@
 //usage:       "Name:       debian\n"
 //usage:       "Address:    127.0.0.1\n"
 
+#ifdef __FreeBSD__
+#include <netinet/in.h> /* for struct in_addr */
+#endif
 #include <resolv.h>
 #include <net/if.h>	/* for IFNAMSIZ */
 //#include <arpa/inet.h>
