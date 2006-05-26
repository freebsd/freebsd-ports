--- pcard/fat.c.orig	Tue May 23 15:25:02 2006
+++ pcard/fat.c	Tue May 23 15:25:54 2006
@@ -27,7 +27,11 @@
 \*****************************************************************************/
 
 #include <stdlib.h>
+#ifdef __FreeBSD__
+#include <inttypes.h>
+#else
 #include <stdint.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
