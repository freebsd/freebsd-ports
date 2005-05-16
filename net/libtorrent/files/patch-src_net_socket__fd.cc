--- src/net/socket_fd.cc.orig
+++ src/net/socket_fd.cc
@@ -28,6 +28,9 @@
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
+#ifdef __FreeBSD__
+# include <netinet/in_systm.h>
+#endif
 #include <netinet/ip.h>
 
 #include "torrent/exceptions.h"
