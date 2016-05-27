--- hpgl.c.orig	2000-08-02 18:31:56 UTC
+++ hpgl.c
@@ -13,9 +13,8 @@
 #include "xgout.h"
 #include "plotter.h"
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
-#define MAX(a,b) ( ((a)>(b)) ? (a) : (b) )
-#define MIN(a,b) ( ((a)<(b)) ? (a) : (b) )
 /* char *malloc(); */
 
 static void hpglText();
