--- src/libslirp.h.orig	2025-05-27 22:38:05 UTC
+++ src/libslirp.h
@@ -26,6 +26,7 @@ typedef ssize_t slirp_ssize_t;
 #include <sys/types.h>
 typedef ssize_t slirp_ssize_t;
 #include <netinet/in.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #define SLIRP_EXPORT
 #endif
