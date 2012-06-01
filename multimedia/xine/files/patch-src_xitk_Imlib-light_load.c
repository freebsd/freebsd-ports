--- src/xitk/Imlib-light/load.c.orig	2010-03-01 18:02:05.000000000 +0100
+++ src/xitk/Imlib-light/load.c	2012-05-06 06:38:35.000000000 +0200
@@ -5,6 +5,7 @@
 #include "Imlib.h"
 #include "Imlib_private.h"
 #include <setjmp.h>
+#include <pngpriv.h>
 
 #ifndef INT_MAX
 #define INT_MAX ((int)((unsigned int)(1 << (8 * sizeof(int) - 1)) - 1))
