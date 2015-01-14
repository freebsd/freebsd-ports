--- src/networking.c.orig	2015-01-14 05:12:08 UTC
+++ src/networking.c
@@ -1,9 +1,9 @@
 #include <arpa/inet.h>
 #include <fcntl.h>
-#include <netinet/in.h>
-#include <netinet/tcp.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#include <netinet/in.h>
+#include <netinet/tcp.h>
 #include <sys/uio.h>
 #include <syslog.h>
 #include <unistd.h>
