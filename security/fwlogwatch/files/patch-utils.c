--- utils.c.orig	2016-02-19 06:35:50.592222000 -0800
+++ utils.c	2021-11-01 08:45:07.736663000 -0700
@@ -9,7 +9,14 @@
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <sys/socket.h>
+#define _KERNEL
+#include <sys/param.h>
+#if __FreeBSD_version > 1400038
+#include <stdbool.h>
+#endif
 #include <netinet/in.h>
+#undef _KERNEL
 #include <arpa/inet.h>
 #include <stdarg.h>
 #include "main.h"
