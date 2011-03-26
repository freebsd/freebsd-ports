--- a/telnet.c
+++ b/telnet.c
@@ -12,7 +12,11 @@
 
 
 
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <string.h>
 //#include <sys/socket.h>
 
