--- server/vino-dbus-listener.c.orig	2009-02-27 20:36:08.000000000 -0500
+++ server/vino-dbus-listener.c	2009-02-27 20:36:30.000000000 -0500
@@ -35,6 +35,9 @@
 #include <string.h>
 #include <unistd.h>
 #include <netdb.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <net/if.h>
 #include <arpa/inet.h>
 
