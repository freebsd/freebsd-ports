--- linux_net.c.orig	Mon Nov  4 21:50:07 2002
+++ linux_net.c	Mon Nov  4 21:50:15 2002
@@ -27,6 +27,7 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <sys/time.h>
 
 /* connect with timeout
 *
