--- ./source4/param/pyparam_util.c.orig	2010-01-11 07:35:28.000000000 +0200
+++ ./source4/param/pyparam_util.c	2012-01-12 19:37:26.501392786 +0200
@@ -21,7 +21,7 @@
 #include "includes.h"
 #include "param/param.h"
 #include "param/loadparm.h"
-#include "pytalloc.h"
+#include "lib/talloc/pytalloc.h"
 
 #define PyLoadparmContext_AsLoadparmContext(obj) py_talloc_get_type(obj, struct loadparm_context)
 
