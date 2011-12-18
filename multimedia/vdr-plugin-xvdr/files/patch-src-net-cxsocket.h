--- a/src/net/cxsocket.h
+++ b/src/net/cxsocket.h
@@ -29,6 +29,9 @@
 #ifndef __CXSOCKET_H
 #define __CXSOCKET_H
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include <inttypes.h>
 #include <sys/types.h>
 #include <sys/socket.h>
