--- ./source4/param/pyparam.c.orig	2011-08-05 17:33:17.000000000 +0200
+++ ./source4/param/pyparam.c	2011-08-05 17:33:48.000000000 +0200
@@ -21,7 +21,7 @@
 #include "includes.h"
 #include "param/param.h"
 #include "param/loadparm.h"
-#include "pytalloc.h"
+#include "lib/talloc/pytalloc.h"
 
 /* There's no Py_ssize_t in 2.4, apparently */
 #if PY_MAJOR_VERSION == 2 && PY_MINOR_VERSION < 5
