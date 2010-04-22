--- util.c.orig	2010-04-20 05:48:52.000000000 +0800
+++ util.c	2010-04-20 05:49:28.000000000 +0800
@@ -31,6 +31,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 #include "babeld.h"
 #include "util.h"
