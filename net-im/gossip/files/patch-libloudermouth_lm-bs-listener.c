--- libloudermouth/lm-bs-listener.c.orig	2008-08-03 14:38:37.000000000 -0400
+++ libloudermouth/lm-bs-listener.c	2008-08-03 14:38:50.000000000 -0400
@@ -27,6 +27,7 @@
 #include <glib.h>
 
 #ifndef G_OS_WIN32
+#include <sys/types.h>
 #include <sys/socket.h> 
 #include <netinet/tcp.h> 
 #endif /* G_OS_WIN32 */
