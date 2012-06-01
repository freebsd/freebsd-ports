--- src/pngcodec.c.orig	2011-01-13 23:28:19.000000000 +0100
+++ src/pngcodec.c	2012-04-27 12:33:01.000000000 +0200
@@ -35,6 +35,7 @@
 #ifdef HAVE_LIBPNG
 
 #include <png.h>
+#include <pngpriv.h>
 #include "gdiplus-private.h"
 #include "pngcodec.h"
 #include <setjmp.h>
