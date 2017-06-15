--- SDLnetsys.h.orig	2012-01-15 16:20:10 UTC
+++ SDLnetsys.h
@@ -54,6 +54,11 @@ typedef int socklen_t;
 #include <fcntl.h>
 #include <netinet/in.h>
 #ifndef __BEOS__
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif /* FreeBSD */
 #include <arpa/inet.h>
 #endif
 #ifdef linux /* FIXME: what other platforms have this? */
