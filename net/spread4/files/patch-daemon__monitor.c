--- daemon/monitor.c.orig	2012-03-21 04:17:52.000000000 +0100
+++ daemon/monitor.c	2013-01-22 12:21:25.000000000 +0100
@@ -39,6 +39,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <sys/stdint.h>
 
 #include "arch.h"
 #include "mutex.h"
