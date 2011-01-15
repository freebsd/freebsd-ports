--- a/src/vdr/input_vdr.c
+++ b/src/vdr/input_vdr.c
@@ -32,6 +32,9 @@
 #include <errno.h>
 #include <pthread.h>
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include <sys/socket.h>
 #include <resolv.h>
 #include <netdb.h>
