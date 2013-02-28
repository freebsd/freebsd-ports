--- libutils/ip_address.c.orig	2013-02-28 14:46:19.800950567 -0500
+++ libutils/ip_address.c	2013-02-28 14:46:32.928950862 -0500
@@ -25,6 +25,7 @@
 #include <stdint.h>
 #include <ctype.h>
 #include <sys/socket.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 
