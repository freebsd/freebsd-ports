--- dist/src/tlink.c.orig	Thu Jul  4 03:03:50 2002
+++ dist/src/tlink.c	Thu Jul  4 03:04:04 2002
@@ -36,9 +36,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <arpa/telnet.h>
-#include <netinet/in.h>
 #include <netdb.h>
 #include <sys/un.h>
 #include <unistd.h>
