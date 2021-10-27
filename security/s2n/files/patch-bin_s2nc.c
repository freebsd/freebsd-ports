--- bin/s2nc.c.orig	2021-10-21 18:41:25 UTC
+++ bin/s2nc.c
@@ -14,6 +14,7 @@
  */
 
 #include <sys/param.h>
+#include <sys/socket.h>
 #include <netdb.h>
 
 #include <unistd.h>
