--- src/net/socket_fd.cc.orig	Mon Apr 18 00:55:09 2005
+++ src/net/socket_fd.cc	Mon Apr 18 17:27:38 2005
@@ -24,9 +24,11 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 
 #include "torrent/exceptions.h"
