--- src/notification_lcdproc.c.orig	2007-09-07 10:53:20.000000000 +0200
+++ src/notification_lcdproc.c	2007-09-07 10:53:34.000000000 +0200
@@ -28,6 +28,7 @@
 #include "gettext.h"
 
 #include <string.h>
+#include <sys/socket.h>
 
 #define NOTIFICATION_LCDPROC_BUFFER_SIZE 8192
 
