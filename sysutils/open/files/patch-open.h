--- open.h.orig	Tue Feb 10 18:10:58 2004
+++ open.h	Tue Feb 10 18:24:48 2004
@@ -1,14 +1,21 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
+#if !defined(__FreeBSD__)
 #include <getopt.h>
+#endif
 #include <string.h>
 #include <fcntl.h>
 #include <dirent.h>
 #include <pwd.h>
+#include <errno.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#if defined(__FreeBSD__)
+#include <sys/consio.h>
+#else
 #include <sys/vt.h>
+#endif
 #include <sys/types.h>
 #include <sys/wait.h>
 
@@ -29,6 +36,10 @@
  */
 #ifdef __linux__
 #define VTNAME "/dev/tty%d"
+#endif
+
+#ifdef __FreeBSD__
+#define VTNAME "/dev/ttyv%x"
 #endif
 
 #ifdef ESIX_5_3_2_D
