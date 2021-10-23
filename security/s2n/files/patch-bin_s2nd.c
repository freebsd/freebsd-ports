--- bin/s2nd.c.orig	2021-10-21 18:40:56 UTC
+++ bin/s2nd.c
@@ -15,6 +15,7 @@
 
 #include <sys/stat.h>
 #include <sys/mman.h>
+#include <sys/socket.h>
 #include <netdb.h>
 #include <signal.h>
 #include <unistd.h>
