--- wml_common/gd/libgd/gd_png.c.orig	Mon Aug 16 11:51:29 2004
+++ wml_common/gd/libgd/gd_png.c	Mon Aug 16 11:51:37 2004
@@ -5,7 +5,7 @@
 #include "gd.h"
 
 #ifdef HAVE_LIBPNG
-#include <png.h>    /* includes zlib.h and setjmp.h */
+#include <libpng/png.h>    /* includes zlib.h and setjmp.h */
 
 #define TRUE 1
 #define FALSE 0
