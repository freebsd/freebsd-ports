--- Net.cpp.orig	Thu Jul 15 16:57:59 2004
+++ Net.cpp	Thu Jul 15 17:01:42 2004
@@ -7,6 +7,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <sys/time.h>
