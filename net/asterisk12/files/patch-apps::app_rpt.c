
$FreeBSD$

--- apps/app_rpt.c
+++ apps/app_rpt.c
@@ -176,7 +176,7 @@
 #include <sys/ioctl.h>
 #include <sys/io.h>
 #include <math.h>
-#include <tonezone.h>
+#include <zaptel/tonezone.h>
 #include <linux/zaptel.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
