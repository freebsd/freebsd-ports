--- smpeg.m4.orig	2001-04-04 20:28:14 UTC
+++ smpeg.m4
@@ -10,7 +10,7 @@ dnl AM_PATH_SMPEG([MINIMUM-VERSION, [ACTION-IF-FOUND [
 ACTION-IF-NOT-FOUND]]])
 dnl Test for SMPEG, and define SMPEG_CFLAGS and SMPEG_LIBS
 dnl
-AC_DEFUN(AM_PATH_SMPEG,
+AC_DEFUN([AM_PATH_SMPEG],
 [dnl
 dnl Get the cflags and libraries from the smpeg-config script
 dnl
