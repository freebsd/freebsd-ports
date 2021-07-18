--- libntech/libutils/known_dirs.c.orig	2021-03-18 08:19:43.000000000 -0700
+++ libntech/libutils/known_dirs.c	2021-03-22 10:34:40.223648000 -0700
@@ -22,6 +22,7 @@
   included file COSL.txt.
 */
 
+#include "../config.h"
 #include <known_dirs.h>
 #include <definitions.h>
 #include <file_lib.h>
