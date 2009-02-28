--- stun/utils.h.orig	2009-02-27 23:06:34.000000000 -0500
+++ stun/utils.h	2009-02-27 23:06:43.000000000 -0500
@@ -49,6 +49,7 @@
 #else
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #endif
 
 # ifdef __cplusplus
