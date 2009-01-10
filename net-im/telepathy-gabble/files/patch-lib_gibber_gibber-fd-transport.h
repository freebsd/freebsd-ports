--- lib/gibber/gibber-fd-transport.h.orig	2009-01-08 01:53:58.000000000 -0500
+++ lib/gibber/gibber-fd-transport.h	2009-01-08 01:54:11.000000000 -0500
@@ -23,7 +23,9 @@
 
 #include <glib-object.h>
 
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 
 #include "gibber-transport.h"
