--- sock-stream.h-orig	2010-08-25 20:47:40.000000000 -0500
+++ sock-stream.h	2010-08-25 20:48:19.000000000 -0500
@@ -25,6 +25,8 @@
 
 int socket_to_oct_iostream (int sd);
 
+#include <netinet/in.h>
+
 #endif
 
 /*
