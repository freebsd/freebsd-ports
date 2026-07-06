-- On FreeBSD, <netinet/tcp.h> does not pull in <netinet/in.h>, so
-- IPPROTO_TCP (defined in <netinet/in.h>) is unavailable. Add the
-- missing include explicitly.
--- paddle/phi/core/distributed/store/tcp_utils.h.orig	2026-06-19 18:26:29 UTC
+++ paddle/phi/core/distributed/store/tcp_utils.h
@@ -21,6 +21,7 @@
 #else
 #include <fcntl.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <poll.h>
 #include <sys/socket.h>
