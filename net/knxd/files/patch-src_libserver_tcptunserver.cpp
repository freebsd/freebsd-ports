--- src/libserver/tcptunserver.cpp.orig	2025-07-28 13:47:46 UTC
+++ src/libserver/tcptunserver.cpp
@@ -23,6 +23,7 @@
 
 #include <unistd.h>
 #include <netinet/tcp.h>
+#include <sys/socket.h>
 #include <sys/un.h>
 #include <arpa/inet.h>
 
