--- src/sn_resolv.c.orig	2020-04-20 01:57:30 UTC
+++ src/sn_resolv.c
@@ -2,6 +2,8 @@
 /*  - getaddrbyname: Godmar Back / Shudoh Kazuyuki                       */
 
 #include "sn_defines.h"
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
 
