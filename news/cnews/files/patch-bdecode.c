--- input/bdecode.c.orig	1991-11-04 19:18:39.000000000 +0100
+++ input/bdecode.c	2011-05-12 15:34:41.000000000 +0200
@@ -2,6 +2,7 @@
  * bdecode [file]
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include "coder.h"
 char *myname, *inputfile = "(stdin)";
