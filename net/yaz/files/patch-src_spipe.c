--- src/spipe.c.orig	2025-05-14 00:41:10 UTC
+++ src/spipe.c
@@ -27,6 +27,8 @@
 #include <unistd.h>
 #endif
 
+#include <sys/socket.h>
+
 #ifdef WIN32
 #include <winsock2.h>
 #define YAZ_INVALID_SOCKET INVALID_SOCKET
