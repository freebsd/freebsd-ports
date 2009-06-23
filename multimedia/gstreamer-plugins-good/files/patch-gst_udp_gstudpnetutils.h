--- gst/udp/gstudpnetutils.h.orig	2009-05-25 21:33:52.000000000 +0200
+++ gst/udp/gstudpnetutils.h	2009-05-25 21:34:16.000000000 +0200
@@ -39,10 +39,10 @@
 
 #else
 #include <sys/time.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <net/if.h>
 #include <netdb.h>
-#include <sys/socket.h>
 #include <sys/wait.h>
 #include <arpa/inet.h>
 #include <unistd.h>
