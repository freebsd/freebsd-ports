--- src/seedsprovider/dyn_dns.c.orig	2020-02-23 01:01:26 UTC
+++ src/seedsprovider/dyn_dns.c
@@ -1,7 +1,7 @@
 #include <arpa/inet.h>
 #include <arpa/nameser.h>
 #include <netdb.h>
-#include <resolv.h>
+//#include <resolv.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/socket.h>
