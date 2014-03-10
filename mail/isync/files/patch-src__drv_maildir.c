--- ./src/drv_maildir.c.orig	2013-12-18 18:58:26.000000000 +0100
+++ ./src/drv_maildir.c	2014-03-10 17:37:57.712669529 +0100
@@ -43,7 +43,7 @@
 # define LEGACY_FLOCK 1
 #endif
 
-#ifndef _POSIX_SYNCHRONIZED_IO
+#if !defined(_POSIX_SYNCHRONIZED_IO) || defined(__FreeBSD__)
 # define fdatasync fsync
 #endif
 
