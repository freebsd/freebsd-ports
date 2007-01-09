--- mplayerxp/postproc/dsp.c.orig	Sat Jul  2 18:59:04 2005
+++ mplayerxp/postproc/dsp.c	Sun Oct  1 22:10:31 2006
@@ -11,7 +11,7 @@
 /* Design and implementation of different types of digital filters
 
 */
-#include <stdint.h>
+#include <inttypes.h>
 #include <string.h>
 #define __USE_ISOC99 1
 #include <math.h>
