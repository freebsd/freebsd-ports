--- klaptopdaemon/smapidev.c	Mon Apr 28 12:00:07 2003
+++ klaptopdaemon/smapidev.c.new	Mon Jan 26 13:49:25 2004
@@ -34,7 +34,6 @@
 #else
 #include <unistd.h>
 #endif
-#include <getopt.h>
 #include <sys/ioctl.h>
 #include <errno.h>
 #ifdef __linux__
