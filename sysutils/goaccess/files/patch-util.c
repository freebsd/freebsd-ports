--- ./util.c.orig	2012-06-04 04:16:26.000000000 +0200
+++ ./util.c	2012-08-08 20:30:36.000000000 +0200
@@ -28,7 +28,7 @@
 #define _XOPEN_SOURCE 700
 
 #ifdef __FreeBSD__
-#include <sys/socket.h>
+#include <netinet/in.h>
 #endif
 
 #include <arpa/inet.h>
@@ -44,9 +44,9 @@
 #include <time.h>
 #include <unistd.h>
 
-#include "util.h"
 #include "commons.h"
 #include "error.h"
+#include "util.h"
 
 /* helper functions */
 char *
