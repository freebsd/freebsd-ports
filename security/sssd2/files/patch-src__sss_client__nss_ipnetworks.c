--- src/sss_client/nss_ipnetworks.c.orig	2023-05-05 08:11:07 UTC
+++ src/sss_client/nss_ipnetworks.c
@@ -22,6 +22,9 @@
 
 #include "config.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <nss.h>
 #include <netdb.h>
 #include <resolv.h>
