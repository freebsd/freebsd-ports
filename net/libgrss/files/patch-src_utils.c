--- src/utils.c.orig	2015-07-15 20:59:07 UTC
+++ src/utils.c
@@ -28,6 +28,10 @@
 
 #include "utils.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 typedef struct {
 	gchar	*data;
 	gint	length;
