
$FreeBSD$

--- network.c	2002/10/22 09:41:27	1.1
+++ network.c	2002/10/22 09:43:55
@@ -13,9 +13,6 @@
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
-#include <sys/socket.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
 #include <netdb.h>
 #include <fcntl.h>
 #include <unistd.h>
