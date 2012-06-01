--- exp-gfx.c.orig	2007-12-03 03:56:06.000000000 +0100
+++ exp-gfx.c	2012-05-05 08:55:49.000000000 +0200
@@ -6,6 +6,7 @@
 
 #include "lang.h"
 #include "export.h"
+#include "zlib.h"
 
 #include "font.h"
 #define WW	(W*CW)			/* pixel width of window */
