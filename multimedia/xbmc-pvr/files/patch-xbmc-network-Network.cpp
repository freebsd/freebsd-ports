--- xbmc/network/Network.cpp.orig
+++ xbmc/network/Network.cpp
@@ -31,6 +31,9 @@
 
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 using namespace std;
 
