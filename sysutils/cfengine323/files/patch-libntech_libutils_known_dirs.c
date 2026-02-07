--- libntech/libutils/known_dirs.c.orig	2023-12-01 14:09:56.000000000 -0800
+++ libntech/libutils/known_dirs.c	2023-12-05 20:25:45.098318000 -0800
@@ -21,6 +21,7 @@
   included file COSL.txt.
 */
 
+#include "../config.h"
 #include <platform.h>
 #include <known_dirs.h>
 #include <definitions.h>
