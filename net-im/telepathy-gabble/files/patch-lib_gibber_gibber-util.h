--- lib/gibber/gibber-util.h.orig	2009-01-08 01:55:08.000000000 -0500
+++ lib/gibber/gibber-util.h	2009-01-08 01:56:05.000000000 -0500
@@ -20,6 +20,9 @@
 #ifndef __GIBBER_UTIL_H__
 #define __GIBBER_UTIL_H__
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 
 #include <glib.h>
