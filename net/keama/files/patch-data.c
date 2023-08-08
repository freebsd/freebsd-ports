--- keama/data.c.orig	2022-09-28 14:39:15 UTC
+++ keama/data.c
@@ -23,6 +23,7 @@
 #include "data.h"
 
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <assert.h>
 #include <stdlib.h>
