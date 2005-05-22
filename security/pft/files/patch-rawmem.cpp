--- rawmem.cpp.orig	Sun May 22 19:17:40 2005
+++ rawmem.cpp	Sun May 22 19:18:34 2005
@@ -11,6 +11,8 @@
 #ifndef UNIX
 #include <winsock2.h>
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #endif //UNIX
 
