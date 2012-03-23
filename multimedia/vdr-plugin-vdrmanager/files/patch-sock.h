--- a/sock.h
+++ b/sock.h
@@ -7,6 +7,9 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include <string>
 
 using namespace std;
