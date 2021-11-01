--- resolve.c.orig	2016-02-19 06:35:50.592222000 -0800
+++ resolve.c	2021-11-01 08:44:17.362963000 -0700
@@ -5,7 +5,13 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#define _KERNEL
+#include <sys/param.h>
+#if __FreeBSD_version > 1400038
+#include <stdbool.h>
+#endif
 #include <netinet/in.h>
+#undef _KERNEL
 #include <arpa/inet.h>
 #include <sys/socket.h>
 #include <netdb.h>
