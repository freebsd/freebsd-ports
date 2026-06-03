--- networking/nslookup.c.orig	2024-04-16 07:23:50 UTC
+++ networking/nslookup.c
@@ -36,6 +36,9 @@
 
 #if !ENABLE_FEATURE_NSLOOKUP_BIG
 
+#ifdef __FreeBSD__
+#include <netinet/in.h> /* for struct in_addr */
+#endif
 #include <resolv.h>
 //#include <arpa/inet.h>
 //#include <netdb.h>
