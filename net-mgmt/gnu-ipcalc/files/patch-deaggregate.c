--- deaggregate.c.orig	2021-06-06 18:56:02 UTC
+++ deaggregate.c
@@ -23,6 +23,7 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <ctype.h>
+#include <sys/socket.h>
 
 #include "ipcalc.h"
 #include "ipv6.h"
