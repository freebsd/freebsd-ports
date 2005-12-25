--- src/dhcp.c.orig	Mon Dec 26 08:22:52 2005
+++ src/dhcp.c	Mon Dec 26 08:29:56 2005
@@ -37,9 +37,12 @@
 #include <string.h>
 #include <errno.h>
 #include <fcntl.h>
+#if __FreeBSD_version > 500000
 #include <stdint.h> /* ISO C99 types */
-#include <arpa/inet.h>
+#endif
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 
 #if defined(__linux__)
 #include <linux/if.h>
