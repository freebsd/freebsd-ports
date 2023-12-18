--- src/common/callerid.h.orig	2023-06-15 19:16:14 UTC
+++ src/common/callerid.h
@@ -43,6 +43,7 @@
 #ifdef __FreeBSD__
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <netdb.h>
 #endif
 
 typedef struct {
