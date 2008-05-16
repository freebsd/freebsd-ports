--- spserver/spporting.hpp.orig	2008-04-19 20:33:45.000000000 +0800
+++ spserver/spporting.hpp	2008-05-16 09:50:37.000000000 +0800
@@ -12,11 +12,13 @@
 
 #else
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netinet/tcp.h>
 #include <syslog.h>
+#include <sys/uio.h>
 #include <unistd.h>
 #include <sys/time.h>
 
