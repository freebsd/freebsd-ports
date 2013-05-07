--- m4/cho-libs.m4.orig	2013-05-07 15:29:52.000000000 +0900
+++ m4/cho-libs.m4	2013-05-07 15:45:02.000000000 +0900
@@ -60,7 +60,8 @@
   [struct paper *p;],
   [AC_MSG_RESULT(yes)
    AC_SEARCH_LIBS([paperpswidth], [paper],
-    [AC_DEFINE(HAVE_LIBPAPER, 1, [Define if you have libpaper])])],
+    [AC_DEFINE(HAVE_LIBPAPER, 1, [Define if you have libpaper])]m
+    [], [LIBS="-lpaper $LIBS"])],
   [CPPFLAGS=$_cppflags
    LDDFLAGS=$_ldflags
    AC_MSG_RESULT(no)])
