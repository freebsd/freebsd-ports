--- ./xbmc/DetectDVDType.cpp.orig	2010-10-11 17:15:33.000000000 +0200
+++ ./xbmc/DetectDVDType.cpp	2010-12-01 12:17:34.238812978 +0100
@@ -34,7 +34,7 @@
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <linux/cdrom.h>
 #endif
 #endif
