
$FreeBSD$

--- osipua/src/udp.c	2002/12/30 08:44:53	1.1
+++ osipua/src/udp.c	2002/12/30 08:45:01
@@ -19,8 +19,8 @@
 */
 
 
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
