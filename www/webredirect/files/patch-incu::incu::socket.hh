
$FreeBSD$

--- incu/incu/socket.hh	2001/03/14 15:11:52	1.1
+++ incu/incu/socket.hh	2001/03/14 15:12:11
@@ -1,5 +1,6 @@
 #ifndef INCU_SOCKET
 #define INCU_SOCKET
+#include <sys/types.h>
 #include <netdb.h>		// Needed by <sys/socket.h> on some systems
 #include <sys/socket.h>
 #include <netinet/in.h>
