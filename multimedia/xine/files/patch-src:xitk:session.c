--- src/xitk/session.c.orig	Sat Feb  1 21:23:01 2003
+++ src/xitk/session.c	Sat Feb  1 21:25:03 2003
@@ -41,6 +41,7 @@
 #include <sys/stat.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <sys/select.h>
 #include <errno.h>
 
 #include "common.h"
