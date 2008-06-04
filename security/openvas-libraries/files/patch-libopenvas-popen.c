--- libopenvas/popen.c.orig	2008-04-26 23:50:53.000000000 +0900
+++ libopenvas/popen.c	2008-04-26 23:51:11.000000000 +0900
@@ -26,6 +26,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <signal.h>
+#include <sys/resource.h>
 
 #include "system.h"
 
