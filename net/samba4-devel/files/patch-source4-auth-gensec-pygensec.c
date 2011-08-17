--- ./source4/auth/gensec/pygensec.c.orig	2010-01-11 06:35:28.000000000 +0100
+++ ./source4/auth/gensec/pygensec.c	2011-08-05 17:51:42.000000000 +0200
@@ -22,7 +22,7 @@
 #include "auth/gensec/gensec.h"
 #include "libcli/util/pyerrors.h"
 #include "scripting/python/modules.h"
-#include "pytalloc.h"
+#include "lib/talloc/pytalloc.h"
 #include <tevent.h>
 
 #ifndef Py_RETURN_NONE
