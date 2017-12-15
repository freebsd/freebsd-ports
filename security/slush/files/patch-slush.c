--- slush.c.orig	1999-05-07 02:24:09 UTC
+++ slush.c
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
