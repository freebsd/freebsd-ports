--- lib/gibber/gibber-xmpp-connection-listener.c.orig	2010-05-20 06:10:39.000000000 -0400
+++ lib/gibber/gibber-xmpp-connection-listener.c	2010-07-24 20:48:34.000000000 -0400
@@ -23,6 +23,7 @@
 #include <string.h>
 #include <time.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 #include <unistd.h>
 #include <errno.h>
 
