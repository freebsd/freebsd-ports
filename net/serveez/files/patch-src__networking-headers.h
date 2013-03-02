--- src/networking-headers.h.orig
+++ src/networking-headers.h
@@ -25,6 +25,8 @@
  */
 # define IPV6_OK  0
 #else
+# include <sys/types.h>
+# include <sys/socket.h>
 # include <arpa/inet.h>
 # include <netinet/in.h>
 /* See:
