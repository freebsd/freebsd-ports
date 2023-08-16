--- src/ip-util.h.orig	2023-08-15 11:26:31.522070000 +0300
+++ src/ip-util.h	2023-08-15 11:28:31.360118000 +0300
@@ -24,6 +24,7 @@
 
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <sys/types.h>
 
 #define MAX_IP_STR 46
 // Lower MTU bound is the value defined in RFC 791
