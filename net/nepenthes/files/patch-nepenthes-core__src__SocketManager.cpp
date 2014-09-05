--- nepenthes-core/src/SocketManager.cpp.orig
+++ nepenthes-core/src/SocketManager.cpp
@@ -36,7 +36,8 @@
 #include <poll.h>
 #include <sys/types.h>
 #include <sys/socket.h>
-#include <errno.h>
+#include <cstdlib>
+#include <cerrno>
 #include <netinet/in.h>
 #include <net/if.h>
 #include <arpa/inet.h>
