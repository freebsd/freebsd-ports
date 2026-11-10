-- Include <netinet/in.h> for sockaddr_in, IPPROTO_TCP and INADDR_LOOPBACK
-- On FreeBSD <arpa/inet.h> and <sys/socket.h> do not declare them, which breaks the tests build

--- tests/core/io_utilities_test.cpp.orig
+++ tests/core/io_utilities_test.cpp
@@ -13,6 +13,7 @@
 #include <winsock2.h>
 #else
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <unistd.h>
 #endif
