--- src/xitk/session.c.orig	Mon Mar  3 23:43:45 2003
+++ src/xitk/session.c	Tue Mar 25 00:11:39 2003
@@ -41,6 +41,7 @@
 #include <sys/stat.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <sys/select.h>
 #include <errno.h>
 
 #include "common.h"
