--- eratspeed.c.orig	2009-03-27 09:16:52.000000000 -0300
+++ eratspeed.c	2009-03-27 09:18:29.000000000 -0300
@@ -1,6 +1,8 @@
 #define B32 1001
 #define B (B32 * 32)
 
+#include <stdio.h>
+#include <stdlib.h>
 #include "timing.h"
 #include "uint32.h"
 
