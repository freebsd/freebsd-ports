--- ./src/modules/videostab/stab/estimate.c.orig	2011-10-31 18:26:04.000000000 +0100
+++ ./src/modules/videostab/stab/estimate.c	2011-11-02 03:11:11.597636807 +0100
@@ -18,7 +18,7 @@
 #include <stdlib.h>
 #include <math.h>
 #include <string.h>
-#if !defined(__DARWIN__)
+#if !defined(__DARWIN__) && !defined(__FreeBSD__)
 #include <values.h>
 #endif
 
