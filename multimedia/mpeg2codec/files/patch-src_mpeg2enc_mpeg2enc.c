--- ./src/mpeg2enc/mpeg2enc.c	1996/11/25 21:18:23	1.1
+++ ./src/mpeg2enc/mpeg2enc.c	1996/11/25 21:22:40
@@ -29,6 +29,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <floatingpoint.h>
 
 #define GLOBAL /* used by global.h */
 #include "config.h"
@@ -50,6 +51,12 @@
     printf("Usage: mpeg2encode in.par out.m2v\n");
     exit(0);
   }
+
+  /*
+   * this prevents a floating point exception in calcSNR (stats.c) when
+   * working on black and white images (charnier@lirmm.fr)
+   */
+  fpsetmask(0);
 
   /* read parameter file */
   readparmfile(argv[1]);
