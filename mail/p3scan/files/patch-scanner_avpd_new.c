--- scanner_avpd_new.c.orig	Mon May  1 00:52:11 2006
+++ scanner_avpd_new.c	Mon May  1 00:53:46 2006
@@ -44,7 +44,6 @@
 #include <time.h>
 #include <sys/time.h>
 #include <errno.h>
-#include <malloc.h>
 #include <sys/un.h>
 #include <sys/socket.h>
 #include <stdarg.h>
@@ -52,6 +51,7 @@
 #include <ctype.h>
 #include <sys/select.h>
 #include <fcntl.h>
+#include <netinet/in.h>
 
 #include "p3scan.h"
 
