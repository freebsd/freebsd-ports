--- slush.c-	Mon Oct 27 06:19:50 2003
+++ slush.c	Mon Oct 27 06:21:46 2003
@@ -34,7 +34,10 @@
 #include <signal.h>
 #include <string.h>
 #include <stdlib.h>
+#include <sys/param.h>
+#if __FreeBSD_version >= 500000
 #include <getopt.h>
+#endif
 #include <termios.h>
 #include <pwd.h>
 #include <sys/ioctl.h>
