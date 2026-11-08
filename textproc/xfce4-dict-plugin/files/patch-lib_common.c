--- lib/common.c.orig	2026-08-18 20:52:36 UTC
+++ lib/common.c
@@ -25,6 +25,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdarg.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <netinet/tcp.h>
 #include <gtk/gtk.h>
