--- xvt/xvt.h.orig	2010-08-24 07:26:11.000000000 +0000
+++ xvt/xvt.h	2010-08-24 07:27:42.000000000 +0000
@@ -59,10 +59,14 @@
 int unlockpt(int);
 char *ptsname(int);
 #else /* !SUNOS5 */
+#ifdef __FreeBSD__
+#include <sys/ioctl.h>
+#else /* !FreeBSD */
 /*#ifndef LINUX*/
 #ifndef linux
 int ioctl(int fd, unsigned request, char *arg);
 #endif /* LINUX */
+#endif /* FreeBSD */
 #endif /* !SUNOS5 */
 
 
