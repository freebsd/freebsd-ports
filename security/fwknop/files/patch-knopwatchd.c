--- knopwatchd.c.orig  2007-11-21 20:59:13.000000000 +0200
+++ knopwatchd.c       2007-11-21 21:03:55.000000000 +0200
@@ -38,7 +38,7 @@
 #include "fwknop.h"
 
 /* defines */
-#define FWKNOP_CONF "/etc/fwknop/fwknop.conf"
+#define FWKNOP_CONF "%%PREFIX%%/etc/fwknop/fwknop.conf"
 
 /* globals */
 unsigned short int fwknopd_syscalls_ctr = 0;
