
$FreeBSD$

--- channels/chan_iax2.c	2004/04/29 21:36:51	1.1
+++ channels/chan_iax2.c	2004/04/29 21:37:10
@@ -52,7 +52,7 @@
 #include <sys/stat.h>
 #ifdef IAX_TRUNKING
 #include <sys/ioctl.h>
-#include <linux/zaptel.h>
+#include <zaptel.h>
 #endif
 #ifdef MYSQL_FRIENDS
 #include <mysql/mysql.h>
