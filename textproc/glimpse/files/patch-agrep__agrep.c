--- ./agrep/agrep.c.orig	2000-03-08 18:51:03.000000000 +0000
+++ ./agrep/agrep.c	2014-01-27 21:40:18.000000000 +0000
@@ -3,6 +3,7 @@
  * bgopal: (1993-4) added a library interface and removed some bugs: also
  * selectively modified many routines to work with our text-compression algo.
  */
+#include <sys/types.h>
 #include <sys/stat.h>
 #include "agrep.h"
 #include "checkfile.h"
