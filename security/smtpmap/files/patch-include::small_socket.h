--- include/small_socket.h.orig	Tue Oct 29 19:16:01 2002
+++ include/small_socket.h	Tue Jun 17 01:30:21 2003
@@ -8,8 +8,8 @@
 #define __SMALL_SOCKET_H
 
 extern "C" {
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/time.h>	// For NetBSD compatibility
 #include <netinet/in.h>
 #include <fcntl.h>
