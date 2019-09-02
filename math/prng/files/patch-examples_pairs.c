--- examples/pairs.c.orig	2000-10-17 08:39:02.000000000 -0700
+++ examples/pairs.c	2019-09-01 21:02:29.348451000 -0700
@@ -53,6 +53,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include "prng.h"
+#define gets(_a) gets_s(_a, sizeof(_a))
 
 struct prng_struct *generator;
 char outfile[200] = "pairs.out";
