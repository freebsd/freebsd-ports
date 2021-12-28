--- src/libslirp.h.orig	2021-06-18 07:49:56 UTC
+++ src/libslirp.h
@@ -12,6 +12,7 @@
 #include <in6addr.h>
 #else
 #include <netinet/in.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #endif
 
