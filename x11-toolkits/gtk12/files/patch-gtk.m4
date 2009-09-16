--- gtk.m4.orig
+++ gtk.m4
@@ -4,7 +4,7 @@
 dnl AM_PATH_GTK([MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND [, MODULES]]]])
 dnl Test for GTK, and define GTK_CFLAGS and GTK_LIBS
 dnl
-AC_DEFUN(AM_PATH_GTK,
+AC_DEFUN([AM_PATH_GTK],
 [dnl 
 dnl Get the cflags and libraries from the gtk-config script
 dnl
