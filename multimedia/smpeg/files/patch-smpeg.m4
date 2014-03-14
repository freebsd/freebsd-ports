--- smpeg.m4.orig	2001-04-05 00:28:14.000000000 +0400
+++ smpeg.m4	2014-02-14 18:19:27.566113006 +0400
@@ -10,7 +10,7 @@
 ACTION-IF-NOT-FOUND]]])
 dnl Test for SMPEG, and define SMPEG_CFLAGS and SMPEG_LIBS
 dnl
-AC_DEFUN(AM_PATH_SMPEG,
+AC_DEFUN([AM_PATH_SMPEG],
 [dnl
 dnl Get the cflags and libraries from the smpeg-config script
 dnl
