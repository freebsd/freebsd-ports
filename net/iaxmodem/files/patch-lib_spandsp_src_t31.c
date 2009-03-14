--- lib/spandsp/src/t31.c  2009-03-14 05:26:02.000000000 +0100
+++ lib/spandsp/src/t31.c  2009-03-14 05:26:28.000000000 +0100
@@ -42,7 +42,7 @@
 #include <memory.h>
 #include <string.h>
 #include <ctype.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "floating_fudge.h"
 #if defined(HAVE_TGMATH_H)
 #include <tgmath.h>
