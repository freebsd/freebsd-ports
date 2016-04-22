--- utils.c.orig	2016-02-19 06:35:50.592222000 -0800
+++ utils.c	2016-04-21 19:36:08.436094000 -0700
@@ -9,7 +9,10 @@
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <sys/socket.h>
+#define _KERNEL
 #include <netinet/in.h>
+#undef _KERNEL
 #include <arpa/inet.h>
 #include <stdarg.h>
 #include "main.h"
