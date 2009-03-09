--- src/rmd_make_dummy_pointer.c.orig	2009-03-09 15:04:26.000000000 +0800
+++ src/rmd_make_dummy_pointer.c	2009-03-09 15:04:39.000000000 +0800
@@ -31,7 +31,7 @@
 #include "rmd_types.h"
 
 #include <X11/Xlib.h>
-
+#include <stdlib.h>
 
 unsigned char *MakeDummyPointer(Display *display,
                                 DisplaySpecs *specs,
