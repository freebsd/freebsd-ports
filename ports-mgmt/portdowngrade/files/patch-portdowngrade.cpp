--- portdowngrade/portdowngrade.cpp.orig	2004-12-28 00:34:52.000000000 -0800
+++ portdowngrade/portdowngrade.cpp	2010-02-09 23:04:21.480393138 -0800
@@ -28,6 +28,8 @@
 #include <dirent.h>
 #include <termios.h>
 #include <fcntl.h>
+#include <string.h>
+#include <limits.h>
 #ifndef TIOCGWINSIZE
 #include <sys/ioctl.h>
 #endif
