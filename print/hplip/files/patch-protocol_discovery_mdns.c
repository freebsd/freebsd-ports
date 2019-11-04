--- protocol/discovery/mdns.c.orig	2019-10-22 06:18:12 UTC
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
@@ -85,6 +89,11 @@ static int mdns_open_socket(int *psocket)
 
     /* Get rid of "address already in use" error message. */
     if (setsockopt(udp_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1)
+    {
+        BUG("unable to setsockopt: %m\n");
+        goto bugout;
+    }
+    if (setsockopt(udp_socket, SOL_SOCKET, SO_REUSEPORT, &yes, sizeof(yes)) == -1)
     {
         BUG("unable to setsockopt: %m\n");
         goto bugout;
