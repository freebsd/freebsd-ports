--- ext/gd/config.m4.orig	Mon Jun  4 10:36:47 2001
+++ ext/gd/config.m4	Fri Oct 26 20:30:41 2001
@@ -174,7 +174,9 @@
   AC_CHECK_LIB(gd, gdImageString16,        [AC_DEFINE(HAVE_LIBGD13, 1, [ ])])
   AC_CHECK_LIB(gd, gdImagePaletteCopy,     [AC_DEFINE(HAVE_LIBGD15, 1, [ ])])
   AC_CHECK_LIB(gd, gdImageCreateFromPng,   [AC_DEFINE(HAVE_GD_PNG,  1, [ ])])
-  AC_CHECK_LIB(gd, gdImageCreateFromGif,   [AC_DEFINE(HAVE_GD_GIF,  1, [ ])])
+  AC_CHECK_LIB(gd, gdImageCreateFromGif,   [AC_DEFINE(HAVE_GD_GIF_READ,  1, [ ])])
+  AC_CHECK_LIB(gd, gdImageGif,             [AC_DEFINE(HAVE_GD_GIF_CREATE,  1, [ ])])
+  AC_CHECK_LIB(gd, gdImageCreateFromGd2,   [AC_DEFINE(HAVE_GD_GD2,  1, [ ])])
   AC_CHECK_LIB(gd, gdImageWBMP,            [AC_DEFINE(HAVE_GD_WBMP, 1, [ ])])
   AC_CHECK_LIB(gd, gdImageCreateFromJpeg,  [AC_DEFINE(HAVE_GD_JPG,  1, [ ])])
   AC_CHECK_LIB(gd, gdImageCreateFromXpm,   [AC_DEFINE(HAVE_GD_XPM,  1, [ ])])
