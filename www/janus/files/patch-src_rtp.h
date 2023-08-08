--- src/rtp.h.orig	2023-05-21 03:47:10 UTC
+++ src/rtp.h
@@ -15,6 +15,8 @@
 
 #include <arpa/inet.h>
 #if defined (__MACH__) || defined(__FreeBSD__)
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <machine/endian.h>
 #define __BYTE_ORDER BYTE_ORDER
 #define __BIG_ENDIAN BIG_ENDIAN
