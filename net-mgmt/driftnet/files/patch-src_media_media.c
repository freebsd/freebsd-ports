--- src/media/media.c.orig	2022-04-16 21:14:04 UTC
+++ src/media/media.c
@@ -17,6 +17,7 @@
 #include "compat/compat.h"
 
 #include <string.h>
+#include <sys/types.h>
 
 #include "common/util.h"
 #include "common/tmpdir.h"
