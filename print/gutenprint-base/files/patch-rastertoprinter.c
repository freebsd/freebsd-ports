--- src/cups/rastertoprinter.c.orig	Fri Sep 20 11:36:56 2002
+++ src/cups/rastertoprinter.c	Wed Oct 16 22:20:32 2002
@@ -49,6 +49,9 @@
  * Include necessary headers...
  */
 
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
 #include <cups/cups.h>
 #include <cups/ppd.h>
 #include <cups/raster.h>
