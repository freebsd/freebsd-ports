--- keama/confparse.c.orig	2022-09-28 14:39:15 UTC
+++ keama/confparse.c
@@ -26,6 +26,7 @@
 #include "keama.h"
 
 #include <sys/errno.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <assert.h>
 #include <ctype.h>
