--- src/lib/proxy_factory.c.orig	2009-02-26 23:49:38.000000000 -0500
+++ src/lib/proxy_factory.c	2009-02-26 23:49:58.000000000 -0500
@@ -26,6 +26,7 @@
 #include <dlfcn.h>
 #include <math.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <pthread.h>
 
