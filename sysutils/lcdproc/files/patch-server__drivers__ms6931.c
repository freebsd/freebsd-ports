--- ./server/drivers/ms6931.c.orig	Wed May  3 15:54:21 2006
+++ ./server/drivers/ms6931.c	Wed May  3 15:54:32 2006
@@ -32,6 +32,7 @@
 #include <string.h>
 #include <errno.h>
 #include <syslog.h>
+#include <sys/time.h>
 
 #ifdef HAVE_CONFIG_H
 # include "config.h"
