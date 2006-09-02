--- src/gtkenhancedscale.c.orig	Thu Jul 20 05:47:54 2006
+++ src/gtkenhancedscale.c	Sat Sep  2 19:54:17 2006
@@ -33,7 +33,7 @@
 #include "gtkenhancedscale.h"
 #include <string.h>
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <math.h>
 
 #undef FANCY
