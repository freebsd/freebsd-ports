--- keama/parse.c.orig	2022-09-28 14:39:15 UTC
+++ keama/parse.c
@@ -24,6 +24,7 @@
 #include "keama.h"
 
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <ctype.h>
 #include <netdb.h>
