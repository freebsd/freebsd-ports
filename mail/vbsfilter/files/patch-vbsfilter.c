--- vbsfilter-1.11.c.orig	Thu Jan 16 04:21:30 2003
+++ vbsfilter-1.11.c	Thu Jan 16 04:27:36 2003
@@ -13,6 +13,12 @@
 #include <termios.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <ctype.h>
+#include <stdlib.h>
+#include <netdb.h>
+#include <unistd.h>
+#endif
 #include "libmilter/mfapi.h"
 
 /*
