--- lib/spandsp/src/t38_terminal.c 2009-03-14 05:26:02.000000000 +0100
+++ lib/spandsp/src/t38_terminal.c 2009-03-14 05:26:40.000000000 +0100
@@ -37,7 +37,7 @@
 #include <fcntl.h>
 #include <time.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "floating_fudge.h"
 #if defined(HAVE_TGMATH_H)
 #include <tgmath.h>
