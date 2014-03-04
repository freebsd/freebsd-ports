--- src/fping.h.orig	2014-02-11 08:45:57.099772218 -0500
+++ src/fping.h	2014-02-11 08:47:08.567771444 -0500
@@ -4,6 +4,7 @@
 #define __APPLE_USE_RFC_3542 1
 
 #include <sys/socket.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 
 #ifndef IPV6
