--- draw.c.orig	Tue Nov 13 16:00:39 2001
+++ draw.c	Tue Nov 13 16:00:56 2001
@@ -26,6 +26,7 @@
 #include <glibtop/netload.h>
 
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 
 /*
