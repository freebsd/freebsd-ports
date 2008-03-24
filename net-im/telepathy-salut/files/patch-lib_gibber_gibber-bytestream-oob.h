--- lib/gibber/gibber-bytestream-oob.h.orig	2008-01-17 00:55:20.000000000 -0500
+++ lib/gibber/gibber-bytestream-oob.h	2008-01-17 00:55:54.000000000 -0500
@@ -22,6 +22,7 @@
 
 #include <glib-object.h>
 
+#include <netinet/in.h>
 #include <netdb.h>
 
 #include "gibber-bytestream-iface.h"
