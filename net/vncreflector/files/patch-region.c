
$FreeBSD$

--- region.c.orig
+++ region.c
@@ -70,6 +70,7 @@
 *                                                               *
 *****************************************************************/
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
