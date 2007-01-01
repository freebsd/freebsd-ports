--- vamps/vamps_lxdvdrip.c.orig	Sat Dec 16 13:49:31 2006
+++ vamps/vamps_lxdvdrip.c	Sat Dec 16 13:50:13 2006
@@ -88,6 +88,10 @@
 #include <inttypes.h>
 #include <sys/stat.h>
 
+// strtoull(3)
+#include <stdlib.h>
+#include <limits.h>
+
 #include "ac.h"
 
 
