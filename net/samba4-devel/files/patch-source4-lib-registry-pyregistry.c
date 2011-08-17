--- ./source4/lib/registry/pyregistry.c.orig	2010-01-11 06:35:28.000000000 +0100
+++ ./source4/lib/registry/pyregistry.c	2011-08-05 17:48:51.000000000 +0200
@@ -23,7 +23,7 @@
 #include "libcli/util/pyerrors.h"
 #include "lib/registry/registry.h"
 #include "scripting/python/modules.h" /* for py_iconv_convenience() */
-#include <pytalloc.h>
+#include "lib/talloc/pytalloc.h"
 #include "auth/credentials/pycredentials.h"
 #include "param/pyparam.h"
 
