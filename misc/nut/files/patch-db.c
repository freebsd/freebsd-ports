--- db.c.orig	Wed Jan  7 00:42:33 2004
+++ db.c	Wed Jan  7 00:42:41 2004
@@ -23,11 +23,7 @@
 #include "meal.h"
 #include "options.h"
 #include "util.h"
-#ifndef DOS
-#include <tgmath.h>
-#else
 #include <math.h>
-#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
