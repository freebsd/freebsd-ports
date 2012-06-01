--- 3rdparty/qwtplot3d/3rdparty/gl2ps/gl2ps.c.orig	2011-08-23 11:57:54.000000000 +0200
+++ 3rdparty/qwtplot3d/3rdparty/gl2ps/gl2ps.c	2012-05-09 13:20:35.000000000 +0200
@@ -48,6 +48,7 @@
 
 #if defined(GL2PS_HAVE_LIBPNG)
 #include <png.h>
+#include <zlib.h>
 #endif
 
 /*********************************************************************
