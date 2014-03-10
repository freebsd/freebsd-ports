--- ./src/sync.c.orig	2013-12-18 22:09:33.000000000 +0100
+++ ./src/sync.c	2014-03-10 17:37:57.711669884 +0100
@@ -35,7 +35,7 @@
 #include <errno.h>
 #include <sys/stat.h>
 
-#ifndef _POSIX_SYNCHRONIZED_IO
+#if !defined(_POSIX_SYNCHRONIZED_IO) || defined(__FreeBSD__)
 # define fdatasync fsync
 #endif
 
