--- xdelta.m4.orig	2007-01-28 01:41:44 UTC
+++ xdelta.m4
@@ -4,7 +4,7 @@ dnl
 dnl AM_PATH_XDELTA([MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND [, MODULES]]]])
 dnl Test for XDELTA, and define XDELTA_CFLAGS and XDELTA_LIBS, if "gmodule" or
 dnl
-AC_DEFUN(AM_PATH_XDELTA,
+AC_DEFUN([AM_PATH_XDELTA],
 [dnl
 dnl Get the cflags and libraries from the xdelta-config script
 dnl
