--- lib/gibber/gibber-xmpp-connection-listener.c.orig	2008-01-17 00:56:23.000000000 -0500
+++ lib/gibber/gibber-xmpp-connection-listener.c	2008-01-17 00:56:46.000000000 -0500
@@ -24,6 +24,7 @@
 #include <time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <unistd.h>
 #include <errno.h>
