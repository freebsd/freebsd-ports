--- src/watch.c.orig	2026-01-29 09:10:29 UTC
+++ src/watch.c
@@ -49,6 +49,7 @@
 #include <sys/ioctl.h>
 #include <sys/time.h>
 #include <sys/wait.h>
+#include <sys/stat.h>
 #include <termios.h>
 #include <time.h>
 #include <unistd.h>
