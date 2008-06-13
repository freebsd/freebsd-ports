--- knopmd.c.orig      2007-11-21 20:59:13.000000000 +0200
+++ knopmd.c   2007-11-21 21:03:20.000000000 +0200
@@ -39,7 +39,7 @@
 #include <getopt.h>
 
 /* defines */
-#define FWKNOP_CONF "/etc/fwknop/fwknop.conf"
+#define FWKNOP_CONF "%%PREFIX%%/etc/fwknop/fwknop.conf"
 
 /* globals */
 static volatile sig_atomic_t received_sighup = 0;
