
$FreeBSD$

--- channels/chan_zap.c	2004/04/29 21:36:51	1.1
+++ channels/chan_zap.c	2004/04/29 21:37:17
@@ -45,7 +45,7 @@
 #include <stdint.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
-#include <linux/zaptel.h>
+#include <zaptel.h>
 #include <math.h>
 #include <tonezone.h>
 #include <ctype.h>
