--- lib/log.c.orig	2008-01-30 04:37:58.000000000 +0000
+++ lib/log.c	2012-10-14 13:11:34.000000000 +0000
@@ -3,7 +3,7 @@
 #include <stdarg.h>
 #include <string.h>
 #include <stdlib.h>
-#include "libafpclient.h"
+#include "afpfs-ng/libafpclient.h"
 
 void log_for_client(void * priv,
 	enum loglevels loglevel, int logtype, char *format, ...) {
diff -Naur afpfs-ng-0.8.1.orig/lib/loop.c afpfs-ng-0.8.1/lib/loop.c
