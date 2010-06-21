--- mythvideo/mtd/dvdprobe.cpp.orig	2009-09-30 09:40:41.000000000 +0200
+++ mythvideo/mtd/dvdprobe.cpp	2010-03-06 10:00:40.000000000 +0100
@@ -9,7 +9,7 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__)
 #include <sys/ioctl.h>
 #include <linux/cdrom.h>
 #endif
@@ -454,7 +454,7 @@
         return false;
     }
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__)
     //  I have no idea if the following code block
     //  is anywhere close to the "right way" of doing
     //  this, but it seems to work.
