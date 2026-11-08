--- source/ni_util.c.orig	2026-10-17 00:01:03 UTC
+++ source/ni_util.c
@@ -25,7 +25,7 @@
  *  \brief  Utility definitions
  ******************************************************************************/
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
