--- networking/nslookup.c.orig	2019-02-14 13:31:15 UTC
+++ networking/nslookup.c
@@ -34,6 +34,7 @@
 //usage:       "Name:       debian\n"
 //usage:       "Address:    127.0.0.1\n"
 
+#include <netinet/in.h>
 #include <resolv.h>
 #include <net/if.h>	/* for IFNAMSIZ */
 //#include <arpa/inet.h>
