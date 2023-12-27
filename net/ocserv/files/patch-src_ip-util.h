--- src/ip-util.h.orig	2023-12-16 05:18:58 UTC
+++ src/ip-util.h
@@ -24,6 +24,7 @@
 
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <sys/types.h>
 
 // Lower MTU bound is the value defined in RFC 791
 #define RFC_791_MTU (68)
