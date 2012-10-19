--- ./integ-test.c.orig	2012-10-06 22:38:13.000000000 +1000
+++ ./integ-test.c	2012-10-06 22:38:29.000000000 +1000
@@ -9,8 +9,8 @@
 #include <sys/socket.h>
 #include <sys/select.h>
 #include <netdb.h>
-#include <netinet/ip.h>
 #include <netinet/in.h>
+#include <netinet/ip.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
 #include <sys/wait.h>
