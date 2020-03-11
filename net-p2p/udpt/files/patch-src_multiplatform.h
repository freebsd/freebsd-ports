--- src/multiplatform.h.orig	2020-02-02 18:34:05 UTC
+++ src/multiplatform.h
@@ -33,6 +33,7 @@
 #elif defined (linux)
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <arpa/inet.h>
 #include <netinet/ip.h>
 #include <netinet/in.h>
 #include <unistd.h>
