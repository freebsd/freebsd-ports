--- src/fragroute/mod.c.orig	2023-12-31 18:39:02 UTC
+++ src/fragroute/mod.c
@@ -8,11 +8,11 @@
  */
 
 #include "mod.h"
+#include "lib/queue.h"
 #include "defines.h"
 #include "config.h"
 #include "common.h"
 #include "argv.h"
-#include "lib/queue.h"
 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
