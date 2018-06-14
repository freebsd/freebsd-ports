--- src/02_clib/md5.c.orig	2017-02-28 12:02:53 UTC
+++ src/02_clib/md5.c
@@ -47,7 +47,7 @@
 #ifdef HAVE_MALLOC_MALLOC_H
 #  include <malloc/malloc.h>
 #else
-#  include <malloc.h>
+#  include <stdlib.h>
 #endif
 
 #include "md5.h"
