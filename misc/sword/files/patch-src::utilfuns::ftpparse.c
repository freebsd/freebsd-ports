--- src/utilfuns/ftpparse.c.orig	Thu Feb 19 23:22:11 2004
+++ src/utilfuns/ftpparse.c	Thu Feb 19 23:22:19 2004
@@ -21,6 +21,7 @@
 NCSA Telnet FTP server. Has LIST = NLST (and bad NLST for directories).
 */
 
+#include <time.h>
 #include <ftpparse.h>
 
 static long totai(long year,long month,long mday)
