--- ssmtp.c.orig	Sun Dec  8 18:26:20 2002
+++ ssmtp.c	Mon Apr  7 01:24:52 2003
@@ -14,6 +14,7 @@
 */
 #define VERSION "2.60.1"
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <sys/param.h>
