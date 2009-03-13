--- fltk/fltk_cairo.h.orig	2009-03-08 14:41:16.000000000 +0100
+++ fltk/fltk_cairo.h	2009-03-08 14:41:47.000000000 +0100
@@ -35,6 +35,7 @@
 
 #include <fltk/FL_API.h>
 #include <cairo.h>
+#include <string.h> /* for memcpy() */
 
 namespace fltk {
   extern FL_API cairo_t * cr;
