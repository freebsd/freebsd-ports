--- SDLnetsys.h.orig	Sun Jul  2 02:28:47 2000
+++ SDLnetsys.h	Wed Sep 20 18:42:27 2000
@@ -41,6 +41,11 @@
 #include <unistd.h>
 #include <fcntl.h>
 #ifndef __BEOS__
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif /* FreeBSD */
 #include <arpa/inet.h>
 #endif
 #include <netinet/in.h>
