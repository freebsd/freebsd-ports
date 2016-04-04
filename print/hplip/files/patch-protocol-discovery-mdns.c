--- protocol/discovery/mdns.c.orig	2016-02-08 09:43:19 UTC
+++ protocol/discovery/mdns.c
@@ -24,7 +24,11 @@
  Author: Sanjay Kumar
  \*****************************************************************************/
 
-//#include <stdio.h>
+#include <ctype.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <sys/select.h>
 #include <string.h>
 #include <syslog.h>
 #include <sys/socket.h>
@@ -89,6 +93,11 @@ static int mdns_open_socket(int *psocket
         BUG("unable to setsockopt: %m\n");
         goto bugout;
     }
+    if (setsockopt(udp_socket, SOL_SOCKET, SO_REUSEPORT, &yes, sizeof(yes)) == -1)
+    {
+        BUG("unable to setsockopt: %m\n");
+        goto bugout;
+    }
 
     /* Bind the socket to port and IP equal to INADDR_ANY. */
     bzero(&recv_addr, sizeof(recv_addr));
