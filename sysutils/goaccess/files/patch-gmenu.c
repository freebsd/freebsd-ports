--- ./gmenu.c.orig	2012-08-08 20:30:06.000000000 +0200
+++ ./gmenu.c	2012-08-08 20:30:23.000000000 +0200
@@ -24,6 +24,11 @@
 #include <stdlib.h>
 #include <string.h>
 
+/* off_t need sys/types.h on 7.x */
+#if __FreeBSD_cc_version_ < 700022
+#include <sys/types.h>
+#endif
+
 #include "gmenu.h"
 #include "error.h"
 #include "util.h"
