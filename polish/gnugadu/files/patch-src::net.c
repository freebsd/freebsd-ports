$FreeBSD$

--- src/orig.net.c	Mon Dec  3 10:29:15 2001
+++ src/net.c	Sun Dec 23 21:22:29 2001
@@ -5,6 +5,8 @@
 #include <glib.h>
 #include <gdk/gdk.h>
 
+#include <sys/types.h>
+
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
