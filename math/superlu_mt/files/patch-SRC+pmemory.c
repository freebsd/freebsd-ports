--- SRC/pmemory.c.orig	Thu May  8 22:45:07 2003
+++ SRC/pmemory.c	Thu May  8 22:45:27 2003
@@ -7,7 +7,6 @@
  */
 #include <stdlib.h>
 #include <stdio.h>
-#include <malloc.h>
 #include "pdsp_defs.h"
 
 #define XPAND_HINT(memtype, new_next, jcol, param) {\
