--- internal/netxlite/getaddrinfo_cgo.go.orig	1979-11-30 00:00:00 UTC
+++ internal/netxlite/getaddrinfo_cgo.go
@@ -9,6 +9,7 @@ package netxlite
 
 #ifndef _WIN32
 #include <netdb.h> // for getaddrinfo
+#include <sys/socket.h>
 #else
 #include <ws2tcpip.h> // for getaddrinfo
 #endif
