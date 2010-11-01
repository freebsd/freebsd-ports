--- ./enma/src/addr_util.c.orig	2009-03-27 15:06:08.000000000 +0900
+++ ./enma/src/addr_util.c	2010-10-21 09:28:43.000000000 +0900
@@ -18,6 +18,7 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
