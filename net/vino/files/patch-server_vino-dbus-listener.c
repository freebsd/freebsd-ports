--- server/vino-dbus-listener.c.orig	2009-05-18 17:59:03.000000000 +0200
+++ server/vino-dbus-listener.c	2009-05-19 10:13:22.000000000 +0200
@@ -35,6 +35,8 @@
 #include <string.h>
 #include <unistd.h>
 #include <netdb.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
